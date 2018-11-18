//
// Created by yurii on 18.11.18.
//

#ifndef LINEAR_SYSTEM_DIVIDEBYZERRO_H
#define LINEAR_SYSTEM_DIVIDEBYZERRO_H


#include "MathError.h"

class DivideByZero : public MathError {
    double divided, divider;
public:
    DivideByZero(double divided, double divider);
    void printError();
};



#endif //LINEAR_SYSTEM_DIVIDEBYZERRO_H
