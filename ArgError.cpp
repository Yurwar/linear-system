//
// Created by yurii on 18.11.18.
//

#include "ArgError.h"

void ArgError::printError() {
    if(arg != nullptr) {
        std::cout << "Input argument error: " << arg << std::endl;
    } else {
        std::cout << "Input argument error." << std::endl;
    }
}

ArgError::ArgError(char *arg) {
    this->arg = arg;
}
