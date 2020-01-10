#ifndef __EXECUTE_HPP__
#define __EXECUTE_HPP__
#include "rShell.hpp"
#include <string>
using namespace std;

class Execute : public rShell {
	public: 
		Execute(vector<string> argv) : rShell() {
			this->argvString = argv;
		}
		bool execute();
		void exitOut();

	private:
		vector<string> argvString;
};
#endif
