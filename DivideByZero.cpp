//
// Created by yurii on 18.11.18.
//

#include "DivideByZero.h"
#include <iostream>

DivideByZero::DivideByZero(double divided, double divider) {
    this->divided = divided;
    this->divider = divider;
}

void DivideByZero::printError() {
    std::cout << "Divide by zero error:\n" << "Divided: " << divided << "\nDivider: " << divider << std::endl;
}
