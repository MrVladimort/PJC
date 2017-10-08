#include <iostream>

using namespace std;

double* aver(double* arr, size_t size, double& average) {
	double modify;

	for (int i = 0; i < size; i++) {
		average += arr[i];
	}

	average = average / size;
	modify = ((int)average) + 1;

	return &modify;
}

int main() {
	double arr[] = { 1,2,3,4,5,7 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	double average = 0;
	double* p = aver(arr, size, average);
	cout << *p << " " << average << endl;
}