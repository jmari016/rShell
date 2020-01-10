#include "InputRedirect.hpp"
#include <iostream>
using namespace std;
bool InputRedirect::execute() {
	int savedStdIn = dup(0);
	int file_desc = open(this->fileName.c_str(), O_RDONLY);
	if(file_desc < 0) {
        	cout << "Error opening the file" << endl;
		return false;
	}
	dup2(file_desc, 0);
	close(file_desc);
	bool status = lhs->execute();
	dup2(savedStdIn, 0);
	return status;
}
