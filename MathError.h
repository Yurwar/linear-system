//
// Created by yurii on 18.11.18.
//

#ifndef LINEAR_SYSTEM_MATHERROR_H
#define LINEAR_SYSTEM_MATHERROR_H

#include <iostream>
#include "Error.h"

class MathError : public Error {
private:
    double *errValue;
    char *msg;
public:
    MathError(double value);
    MathError(char *msg);
    MathError();
    virtual void printError();
};


#endif //LINEAR_SYSTEM_MATHERROR_H
