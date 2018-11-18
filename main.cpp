#include <iostream>
#include <iomanip>
#include "Linear_System.h"

using namespace std;

int main() {
    int size;
    char sizeArg[5];
    char condition;
    do {
        try {
            cout << "Enter the system size: ";
            cin >> sizeArg;
            if(!isdigit(sizeArg[0])) {
                throw ArgError(sizeArg);
            } else {
                size = atoi(sizeArg);
            }
            LinearSystem ls(size);
            ~ls;
        }
        catch (Error &e) {
            e.printError();
        }
        catch (runtime_error &e) {
            cout << "Runtime error: " << e.what() << endl;
        }
        catch (bad_alloc &e) {
            cout << "Bad allocation\n";
        }
        catch (...) {
            cout << "Undefined exception" << endl;
        }
        cout << "Do you want to continue (y/n): "; cin >> condition;
    } while (condition == 'y' || condition == 'Y');
    cout << "\nМатьора Ю. І., Лабораторна робота №6, 17 варіант, рівень Б\n";
}
