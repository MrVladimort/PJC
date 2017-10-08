#include <iostream>

using namespace std;

void ord3(double& a, double& b, double& c) {
    double wrt;

    if(a > b && a > c){
        wrt = c;
        c = a;
        a = wrt;
    }

    if(b > a && b > c){
        wrt = c;
        c = b;
        b = wrt;
    }

    if(b < a && b < c){
        wrt = a;
        a = b;
        b = wrt;
    }

}
void ord3(double* a, double* b, double* c) {
    double wrt;

    if(*a > *b && *a > *c){
        wrt = *c;
        *c = *a;
        *a = wrt;
    }

    if(*b > *a && *b > *c){
        wrt = *c;
        *c = *b;
        *b = wrt;
    }

    if(*b < *a && *b < *c){
        wrt = *a;
        *a = *b;
        *b = wrt;
    }
}

void getMinMax(double &a, double& b, double& c,
               double*& ptrMin, double*& ptrMax) {
    ord3(a, b, c);
    ptrMin = &a;
    ptrMax = &c;
}
void getMinMax(double *a, double* b, double* c,
               double** ptrMin, double** ptrMax) {
    ord3(*a, *b, *c);
    *ptrMin = a;
    *ptrMax = c;
}

int main() {
    double a, b, c, *ptrMin, *ptrMax;

    a = 2; b = 3; c = 1;
    ord3(a, b, c);
    cout << a << " " << b << " " << c << endl;


    a = 3; b = 2; c = 1;
    ord3(&a, &b, &c);
    cout << a << " " << b << " " << c << endl;


    a = 2; b = 3; c = 1; ptrMin = ptrMax = nullptr;
    getMinMax(a, b, c, ptrMin, ptrMax);
    cout << "Min = " << *ptrMin << "; "
         << "Max = " << *ptrMax << endl;

    a = 3; b = 1; c = 2; ptrMin = ptrMax = nullptr;
    getMinMax(&a, &b, &c, &ptrMin, &ptrMax);
    cout << "Min = " << *ptrMin << "; "
         << "Max = " << *ptrMax << endl;
 }
 