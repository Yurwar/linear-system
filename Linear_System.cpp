#include "Linear_System.h"


using namespace std;




double** LinearSystem::createMatrix() {
    try {
        double **newMatrix = new double *[matrixSize];
        for (int i = 0; i < matrixSize; i++) {
            newMatrix[i] = new double[matrixSize];
        }
        return newMatrix;
    }
    catch (const bad_alloc &e) {
        cout << "Allocation error\n";
    }

}

double** LinearSystem::copyMatrix(double** inputM) {
    try {
        double** outputM = new double* [matrixSize];
        for(int i = 0; i < matrixSize; i++) {
            outputM[i] = new double[matrixSize];
            for(int j = 0; j < matrixSize; j++) {
                outputM[i][j] = inputM[i][j];
            }
        }
        return outputM;
    }
    catch (const bad_alloc &e) {
        cout << "Allocation error\n";
    }

}

void LinearSystem::deleteMatrix(double** matrix) {
    for(int i = 0; i < matrixSize; i++)
        delete matrix[i];
    delete [] matrix;
}

void LinearSystem::printVector(double* vector) {
    for(int i = 0; i < matrixSize; i++) {
        cout << setw(5) << vector[i] << endl;
    }
}

LinearSystem::LinearSystem(int size) {
    if(size < 2) {
        cout << "Size can not be less than 2, size is set to 3\n";
        size = 3;
    }
    matrixSize = size;
    if (matrixSize > 2000) {
        throw overflow_error("Size of system is too large");
    }
    M = createMatrix();
    try {
        freeNumbVector = new double[matrixSize];
    }
    catch (const bad_alloc &e) {
        cout << "Allocation error\n";
    }
    cout << "Coefficient matrix is " << matrixSize << 'x' << matrixSize << '\n';
    for(int i = 0 ; i < matrixSize; i++) {
        cout << "Enter the " << i + 1 << " line: ";
        for(int j = 0; j < matrixSize; j++) {
            char inputArg[20];
            cin >> inputArg;
            if(!isdigit(inputArg[0])) {
                throw ArgError(inputArg);
            } else {
                double arg = atoi(inputArg);
                M[i][j] = arg;
            }
        }
    }
    cout << "Enter the free numbers vector: ";
    for(int i = 0; i < matrixSize; i++) {
        cin >> freeNumbVector[i];
    }
}

void LinearSystem::printMatrix() {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; ++j)
            cout << setw(5) << M[i][j];
        cout << endl;
    }
    cout << endl;
}

double* LinearSystem::findRoots() {
    double **A = copyMatrix(M);
    double *resVector;
    try {
        resVector = new double[matrixSize];
    }
    catch (const bad_alloc &e) {
        cout << "Allocation error\n";
    }
    for(int i = 0; i < matrixSize; i++) {
        resVector[i] = freeNumbVector[i];
    }
    while(A[0][0] == 0){
        int i = 1;
        if(A[i][0] != 0) {
            double *tmp = A[i];
            A[i] = A[0];
            A[0] = tmp;
            double tmpVector = resVector[i];
            resVector[i] = resVector[0];
            resVector[0] = tmpVector;
        } else {
            i++;
        }
    }
    for(int i = 0; i < matrixSize; i++) {
        double a = A[i][i];
        for(int j = 0; j < matrixSize; j++) {
            if(a == 0) {
                throw DivideByZero(A[i][j], a);
            }
            A[i][j] = A[i][j] / a;
        }
        if(a == 0) {
            throw DivideByZero(resVector[i], a);
        }
        resVector[i] = resVector[i] / a;

        for(int k = 0; k < i; k++) {
            a = A[k][i];
            for(int j = 0; j < matrixSize; j++) {
                A[k][j] = A[k][j] - A[i][j] * a;
            }
            resVector[k] = resVector[k] - resVector[i] * a;
        }

        for(int k = i + 1; k < matrixSize; k++) {
            a = A[k][i];
            for(int j = 0; j < matrixSize; j++) {
                A[k][j] = A[k][j] - A[i][j] * a;
            }
            resVector[k] = resVector[k] - resVector[i] * a;
        }
    }
    deleteMatrix(A);
    printVector(resVector);
    return resVector;
}

LinearSystem LinearSystem::operator~() {
    findRoots();
}

void LinearSystem::setMatrix() {
    if(M != nullptr) {
        deleteMatrix(M);
    }
    M = createMatrix();
    cout << "Coefficient matrix is " << matrixSize << 'x' << matrixSize << '\n';
    for(int i = 0 ; i < matrixSize; i++) {
        cout << "Enter the " << i + 1 << " line: ";
        for(int j = 0; j < matrixSize; j++) {
            cin >> M[i][j];
        }
    }
}
double **LinearSystem::getMatrix() {
    return M;
}

void LinearSystem::setNumberVector() {
    if(freeNumbVector != nullptr) {
        delete[] freeNumbVector;
    }
    freeNumbVector = new double[matrixSize];
    cout << "Vector size is " << matrixSize << endl;
    cout << "Enter the free numbers vector: ";
    for(int i = 0; i < matrixSize; i++) {
        cin >> freeNumbVector[i];
    }
}
double *LinearSystem::getNumberVector() {
    return freeNumbVector;
}
