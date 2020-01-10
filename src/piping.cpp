#include "rShell.hpp"
#include "piping.hpp"
#include <limits>
#include <iostream>
using namespace std;
bool Piping::execute() {
	int savedStdIn = dup(0);
	int savedStdOut = dup(1);
	bool status = this->execute(savedStdOut, 0);
	if(dup2(savedStdIn, 0) == -1) {
		cout << "Error on dup2 call 12" << endl;
	}
	if(!status) {
		cout << "Error in pipe execution" << endl;
	}
	return status;
}
bool Piping::execute(int output_fd, int pipeNum) {
	bool leftStatus;
	int status;
	bool rightStatus;
	int pipe_fd[2];
        pipe(pipe_fd); //in pipe, first process writes into pipe and then the output of that pipe becomes the input for the second process
	if(pipe(pipe_fd) == -1) {
		cout << "Error upon creating pipe." << endl;
		return false;
	}
	pid_t pid = fork();
	if(pid < 0) {
		perror("Error upon creating fork");
		return false;
	} else if(pid > 0) { //Parent process should wait for children and call right 
		int status;
                wait(&status); 
                if(status > 0) {return false;}
		dup2(pipe_fd[0], 0);
                dup2(output_fd, 1);
                close(pipe_fd[0]);
                close(pipe_fd[1]);
		close(output_fd);
		rightStatus = right->execute();
		if(pipeNum == 0) {
			return rightStatus;
		} else {
	                if (!rightStatus) {
				exit(1);
		       	}
			exit(0);
		}
	}
	else {//child call left execute
		if(left->isPipe()) {
                int output = dup(pipe_fd[1]);
		close(pipe_fd[1]);
                leftStatus = left->execute(output, ++pipeNum);
		int status;
                wait(&status);
		return leftStatus;
		} else {
			status = dup2(pipe_fd[1], 1);
                        if (status == -1) {
                                cout << "Error in dup2, line 42" << endl;
                        }
                        close(pipe_fd[0]);
                        close(pipe_fd[1]);
			leftStatus = left->execute();
			if(!leftStatus) {exit(1);}
			else {exit(0);}
		}
	}
}

bool Piping::isPipe() {return true;}
