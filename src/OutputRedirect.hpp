#ifndef __OUTPUTREDIRECT_HPP__
#define __OUTPUTREDIRECT_HPP__
#include "rShell.hpp"
#include <string>
#include <iostream> 
class OutputRedirect : public rShell
{
  public:
     OutputRedirect() : rShell() {}
     OutputRedirect(rShell* lhs, string fileName) : rShell() {this->lhs = lhs; this->fileName = fileName;}
     bool execute();
  private: 
	rShell* lhs;
	string fileName;
};
#endif
