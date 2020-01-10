#include "rShell.hpp"
#include "OutputRedirect2.hpp"
using namespace std;
bool OutputRedirect2::execute() {
	int savedStdOut = dup(1);
        int file_desc = open(this->fileName.c_str(), O_WRONLY | O_APPEND);
        if(file_desc < 0) {
                cout << "Error opening the file" << endl;
                return false;
        }
        dup2(file_desc, 1);
        close(file_desc);
        bool status = lhs->execute();
        dup2(savedStdOut, 1);
        return status;
}
