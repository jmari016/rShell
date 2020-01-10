#include <iostream>
#include "ExecuteOR.hpp"
using namespace std;

bool ExecuteOR::execute() {   
    if (!(this->left->execute())) {
        return this->right->execute();
    }
    else { return true; }
}
