#ifndef __EXECUTE_OR_HPP__
#define __EXECUTE_OR_HPP__
#include "rShell.hpp"
using namespace std;

class ExecuteOR : public rShell {
	public:
		ExecuteOR() : rShell() {}
		ExecuteOR(rShell *left, rShell *right) : rShell() {this->left = left; this->right = right;}
		bool execute();
	private:
        	rShell *left;
        	rShell *right;

};

#endif
