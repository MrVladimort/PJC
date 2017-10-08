#include <iostream>
#include <cmath>
using namespace std;
double f1(double x) { return x / 4; }
double f2(double x) { return -2 * x; }
using D2D = double(*)(double);
D2D maxfun(D2D funs[], int size, double a, double b, double* pmax) {
	static const double eps = 1e-4;
	double maxX = a;
	D2D maxFun = funs[0];
	double maxNum = maxFun(a);
	
	for (int i = 0; i < size; i++) {
		for (double j = a; j < b; j += eps) {
			if (funs[i](j) > maxNum) {
				
				maxNum = funs[i](j);
				maxX = j;
				maxFun = funs[i];
				
			}
		}
	}
	
	*pmax = maxX;
	return maxFun;
}
int main() {
	double xmax;
	D2D funs[] = { f1,sin,f2 };
	D2D pf = maxfun(funs, 3, 0, 3, &xmax);
	cout << "xmax = " << xmax << "; f(xmax) = "
		<< pf(xmax) << endl;
}