#ifndef __RSHELL_HPP__
#define __RSHELL_HPP__
#include <cstdio>
#include <cstdlib>
#include <stdio.h> //for perror and fork
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <vector>
#include <fcntl.h>
using namespace std;

class rShell {
	public:
		rShell(){};
		virtual bool execute() = 0;
		virtual bool isPipe() {return false;}
		virtual bool execute(int output_fd, int pipeNum) {return false;}
};

#endif
