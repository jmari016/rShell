# CS 100 Programming Project
**Creators:** Ethan White ~~ SID: 861312702 && Jorge Marin ~~ SID: 862009642

# *Introduction*
Our goal for this assignment is to design a command shell called RShell with C++. The command shell should be designed to contain a prompt that will read a given command and print it on one line. Therefore, the RShell we will design will contain executables that will be located in the specified PATH setting; containing zero or more arguments separated by spaces or connectors (&& and | |). There are three conditions that me and my partner will reference for the connectors of a command used in this assignment. First, if a command is preceded by the “;” connector, then the command will always execute. If a command is followed by the “&&” connector, then the following command is only executed if the first command passes. The final condition is if a command is followed by the “| |” connector, then the next command is executed only if the first command fails. One final note for this assignment is that only commands that can be executed through PATH directories should be used in the shell; therefore, commands like “ls” and “cd” are not needed for this assignment.

# *Design*
![unnamed](https://user-images.githubusercontent.com/56050298/67903884-02760d00-fb2a-11e9-8053-bf3759fe157f.png)

# *Classes* 
**rShell (base class) →**
This class is the implementation, virtual, class that will run functions as they arise in our RShell terminal. 
|| *virtual void print () = 0;* This function is purely virtual, which will permit it to be implemented in parent and subclasses. 
|| *virtual void execute(vector <Executable*> execs) = 0;*   This function is also purely virtual. However, our planned implementation                                                                for sub and parent classes, would be to let the user execute their commands                                                              on the lines given in our shell. It is passed in a vector of executable                                                                  files to be executed depending on the connector.
|| *exit();*         As the name implies, this function will allow the user to exit their current state in the program.

**executable class →** 
This class does not inherit from rShell but is referenced by the CommandLine class. This class stores the information needed for each executable to actually be executed. This includes the number of arguments and an array of null terminated strings.
|| *int argc;*               Variable of type int that stores the number of arguments in the executable
|| *char* argv[ ];*          An array of null terminated strings that stores the contents of each argument
  
**commandLine class →**
This class inherits from rShell and references Executable as it adds executables into a vector.
|| *void print ();*          A function that prints out a command prompt
|| *void extractExecutables(int argc, char* argv[ ]);*    This function takes in two parameters passed in from main and goes through the                                                           entire command line inputted by the user. It extracts all executables and                                                               stores them in a vector of type Executable.
|| *void execute(vector <Executable*> execs);*         This function uses the vector of Executables and determines which of the                                                                execution methods is necessary. It will then create an object of whichever of                                                            the execution methods and call it’s execute function.
  
**execute class →**
This class simply executes a single executable normally, when no connectors are found.
  
**executeAND class →**
A class that will first execute the first Execute* in the vector and will only move on to the next executable in the vector if the first one is successful. 

**executeOR class →**
A class that will execute the first Execute* in the vector and will move onto the next, if and only if, the first one fails.

**executeSEMI class →**
A class that will always execute the first Execute* in the vector, no matter what, and execute the following executables regardless of failure or success.

# *Prototypes & Research*

*Comments included with code for explanations of function calls.*

    #include <iostream>
	#include <stdio.h>
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
                                                     //first item was the executable used to begin main, so not needed for this execution
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
                for (unsigned int i = 0; i < argc; ++i) {//iterate through everything in the argv.
                                //for first and following executables, check last char in string to see if it is ';' connector
                                //if it is, ++connectorCount and next arg is going to be another executable
                                //if its none of these, then its an argument so ++argument
                }
        }
}

# *Roadmap* 
1. [Code the parser function](https://github.com/cs100/assignment-rshell/issues/3)                          
2. [Verify how to access the last char of a string](https://github.com/cs100/assignment-rshell/issues/4)      
3. [Tweak CommandLine class since parsing takes place in main](https://github.com/cs100/assignment-rshell/issues/5)                     
4. [Probably will need to reference Executable class in main to create vector of executables](https://github.com/cs100/assignment-rshell/issues/7)                    
5. [Implement unit testing for execvp process and parsing](https://github.com/cs100/assignment-rshell/issues/8)
6. [Implement integration testing for execvp process and parsing](https://github.com/cs100/assignment-rshell/issues/9)                                            


	

