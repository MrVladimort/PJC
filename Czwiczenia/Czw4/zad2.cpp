#include <iostream>
using namespace std;
size_t length(const char* cstr);
void clean(char*);
int main() {
	char n1[] = "a   bc    def     ghijk";
	cout << "Przed: >" << n1 << "<" << endl;
	clean(n1);
	cout << " Po: >" << n1 << "<" << endl;
	char n2[] = "   a bc     def   ghijk   ";
	cout << "Przed: >" << n2 << "<" << endl;
	clean(n2);
	cout << " Po: >" << n2 << "<" << endl;
	char n3[] = "     ";
	cout << "Przed: >" << n3 << "<" << endl;
	clean(n3);
	cout << " Po: >" << n3 << "<" << endl;
}
size_t length(const char* cstr) {
	const char * end = cstr;
	while (*end++)
		;
	return end - cstr - 1;
}
void clean(char * t) {
	char *result = t;
	int size = length(t);
	bool find = 1;
	int ind = 0;
	int countWords = 0;
	int end = 0;
	for (int i = 0; i < size; i++) {
		for (int j = ind; j < size && find; j++) {
			if (t[j] != ' ') {
				if (j == 0) countWords++;
				if (j != ind) {
					if (countWords == 0) result[i] = t[j];
					else {
						result[i] = ' ';
						result[i + 1] = t[j];
						i++;
					}
					countWords++;
				}
				else  {
					result[i] = t[j];
				}
				ind = j + 1;
				find = 0;
				end = i+1;
			}
		}
		find = 1;
	}
	result[end] = '\0';
	t = result;
}