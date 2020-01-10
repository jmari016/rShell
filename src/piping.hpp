#ifndef __PIPING_HPP__
#define __PIPING_HPP__
#include "rShell.hpp"
using namespace std;
class Piping : public rShell {
    public:
    	Piping() : rShell() {}
    	Piping(rShell *left, rShell *right) : rShell() {this->left = left; this->right = right;}
	bool execute();
    	bool execute(int output_fd, int pipeNum);
	bool isPipe();
    private:
	rShell *left;
	rShell *right;
};
#endif

