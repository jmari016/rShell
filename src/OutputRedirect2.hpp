#ifndef __OUTPUTREDIRECT2_HPP__
#define __OUTPUTREDIRECT2_HPP__
#include "rShell.hpp"
#include <string>
#include <iostream>
class OutputRedirect2 : public rShell {
    public:
    OutputRedirect2() : rShell() {}
    OutputRedirect2(rShell* lhs, string fileName) : rShell() {this->lhs = lhs; this->fileName = fileName;}
    bool execute();
    private: 
	rShell* lhs;
	string fileName;
};
#endif
