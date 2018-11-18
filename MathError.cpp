//
// Created by yurii on 18.11.18.
//

#include "MathError.h"

void MathError::printError() {
    if(msg == nullptr && errValue == nullptr) {
        std::cout << "Math error\n";
    } else if(msg != nullptr) {
        std::cout << "Math error: " << msg << std::endl;
    } else {
        std::cout << "Math error, error value is: " << errValue << std::endl;
    }
}

MathError::MathError(double value) {
    *errValue = value;
}

MathError::MathError(char* msg) {
    this->msg = msg;
}

MathError::MathError() = default;
