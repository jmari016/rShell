#ifndef __EXECUTE_AND_HPP__
#define __EXECUTE_AND_HPP__
#include "rShell.hpp"
using namespace std;

class ExecuteAND : public rShell {
        public:
		ExecuteAND(rShell *left, rShell *right) : rShell() {this->left = left; this->right = right;}
                bool execute();
	private:
		rShell* left;
		rShell* right;
};


#endif
