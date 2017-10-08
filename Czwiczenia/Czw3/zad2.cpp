#include <iostream>

using namespace std;

void histo(int arr[], size_t size) {
	string s;
	cin >> s;

	int max;

	for (int i = 0; i < size; i++) {
		if (i == 0)
			max = arr[i];
		else if (arr[i] > max)
			max = arr[i];
	}


	for (int i = max; i > 0; i--) {
		for (int j = 0; j < size; j++) {
			if (s == "STAR") {
				if (arr[j] >= i)
					cout << "*";
				else
					cout << " ";
			}

			if (s == "EQU") {
				if (arr[j] >= i)
					cout << "=";
				else
					cout << " ";
			}
		}
		cout << endl;
	}
}
int main() {
	int arr[]{ 2,3,2,7,1,10,1,7,2,3,2 };
	size_t size = sizeof(arr) / sizeof(*arr);
	histo(arr, size);
}