//
// Created by yurii on 18.11.18.
//

#ifndef LINEAR_SYSTEM_ARGERROR_H
#define LINEAR_SYSTEM_ARGERROR_H

#include <iostream>
#include "Error.h"

class ArgError : public Error{
private:
    char *arg;
public:
    ArgError() = default;
    ArgError(char *arg);
    void printError();

};


#endif //LINEAR_SYSTEM_ARGERROR_H
