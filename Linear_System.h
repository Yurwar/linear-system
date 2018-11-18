#ifndef LINEAR_SYSTEM_LINEAR_SYSTEM_H
#define LINEAR_SYSTEM_LINEAR_SYSTEM_H

#include <iostream>
#include <iomanip>
#include "MathError.h"
#include "DivideByZero.h"
#include "ArgError.h"

class LinearSystem {
private:
    int matrixSize;
    double** M;
    double* freeNumbVector;
    double** createMatrix();
    double** copyMatrix(double** inputM);
    void deleteMatrix(double** matrix);
    void printVector(double* vector);
public:
    LinearSystem(int);
    void printMatrix();
    double* findRoots();
    LinearSystem operator~();
    void setMatrix();
    double **getMatrix();
    void setNumberVector();
    double *getNumberVector();
};




#endif //LINEAR_SYSTEM_LINEAR_SYSTEM_H
