#ifndef __INPUTREDIRECT_HPP__
#define __INPUTREDIRECT_HPP__
#include "rShell.hpp"
#include <string>
class InputRedirect : public rShell {
  public:
  InputRedirect() : rShell() {}
  InputRedirect(rShell* lhs, string fileName) : rShell() {this->lhs = lhs; this->fileName = fileName;}
  virtual bool execute();
  private:
	rShell* lhs;
	string fileName;
};
#endif
