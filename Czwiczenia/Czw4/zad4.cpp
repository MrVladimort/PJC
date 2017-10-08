#include <iostream>

size_t length(const char* cstr) {
	const char * end = cstr;
	while (*end++)
		;
	return end - cstr - 1;
}
int theSame(const char a[], const char b[]) {
	int size = 0;
	int equal = 0;
	for (int i = 0; i < length(a); i++) {
		if (a[i] == b[i])
			equal++;
		else {
			size += equal*equal;
			equal = 0;
		}
	}
	size += equal*equal;
	return size;
}
int notTheSame(const char a[], const char b[]) {
	int size = 0;
	bool side = (length(a) > length(b));
	int num;
	if (side) 
		num = length(a) - length(b) + 1;
	else 
		num = length(b) - length(a) + 1;
	for (int i = 0; i < num; i++) {
		if (side) {
			if (theSame(b, a) > size)
				size = theSame(b, a);
			a++;
		}
		else {
			if (theSame(a, b) > size)
				size = theSame(a, b);
			b++;
		}
	}
	return size;
}
int simil(const char a[], const char b[]) {
	int size = 0;
	if (length(a) == length(b)) {
		size = theSame(a, b);
	}
	else
		size = notTheSame(a, b);
	return size;
}
int main() {
	char a[] = "AACTACGTC",
		b[] = "ACGTA";
	std::cout << a << " and " << b << " -> "
		<< simil(a, b) << std::endl;
	char c[] = "GCGC",
		d[] = "AGGGCA";
	std::cout << c << " and " << d << " -> "
		<< simil(c, d) << std::endl;
}