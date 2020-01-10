#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

void commandParser(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	string fullcommand;

	cout << "Number of args: " << argc << endl; //This tests that the arguments passed in upon execution is as expected
	cout << "Contents in array: " << endl;
	for (unsigned int i = 0; i < argc; i++) {
		cout << argv[i] << " ";
	}
	cout << endl;
	cout << "Last char in the first string is: " << argv[0][strlen(argv[0]) - 1] << endl;
	char* updatedArgs[] = {argv[1], NULL};

	/*We learned that if we want to execute a file from within the parent process, there are 3 main steps:
 		1) fork the current process
		2) Child process executes the executable using execvp()
		3) Parent process waits for the child process to finish executing, then parent continues with any following lines of code */
	cout << "Beginning a fork" << endl;
	pid_t pid = fork(); //Step 1 starts here
	
	if (pid < 0) { //fork() returns a negative number if an error occurred
		perror("Error upon creating fork"); //perror is what we use to handle a fork error
	}
	else if (pid == 0) { //this code is only executed by child process, 0 = child process
		cout << "This is the child process. pid = " <<  getpid() << endl;
		cout << "Executing " << updatedArgs[0] << endl;
		execvp(updatedArgs[0], updatedArgs); //updatedArgs holds all the information passed in by argv except the first item as the 
						     //first item wsa the executable used to begin main, so not needed for this execution
		cout << "This is code after execvp and should not be executed" << endl; //upon completion of the child process, the child process is killed (this is why we fork)
	}
	else { //this code is only executed by parent process, which is waiting for the child to finish
		waitpid(pid, NULL, 0); //parent waiting
		cout << "This is the parent process. pid = " << getpid() << endl;
	}
	cout << "This should be the last line outputted as the program continues its code" << endl;
		
	return 0;
}

void commandParser(int argc, char* argv[]) {
	int executableCount = 0;
	int connectorCount = 0;
	int argumentCount = 0;
	if (argc > 0) {
		++executableCount; //first command will be executable
		for (unsigned int i = 1; i < argc; ++i) {//iterate through everything in the argv.
				//for first and following executables, check last char in string to see if it is ';' connector
			++executableCount;
				//if it is, ++connectorCount and next arg is going to be another executable
				//if its none of these, then its an argument so ++argument 
		}
	}
}
