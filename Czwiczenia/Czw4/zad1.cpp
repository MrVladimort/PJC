#include <iostream>
using namespace std;

size_t length(const char* cstr);
bool isLetter(char c);
char* reverse(char* cstr);
size_t words(const char* cstr);
size_t words2(const char* cstr);
char* contact(char* t, const char* s);

int main() {
    char s1[] = "Alice in Wonderland!";
    cout << "reverse: " << reverse(s1) << endl;
    cout << "length : " << length(s1) << endl;
    char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
    cout << "words : " << words(s2) << endl;
    cout << "words2 : " << words2(s2) << endl;
    char s3[100] = "Hello";
    cout << "contact : "
         << contact(contact(s3, ", world"), "!") << endl;
    cout << "Is letter: " << isLetter('A') << endl;


}


size_t length(const char* cstr) {
    int count = 0;

    while(cstr[count] != '\0')
        count++;

    return count;
}

bool isLetter(char c) {
    bool a;

    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        a = true;
    else
        a = false;

    return a;
}

char* reverse(char* cstr) {
    size_t t = length(cstr);

    for(int i = 0; i < t/2; i++){
        char wrt = cstr[i];
        cstr[i] = cstr[t-i-1];
        cstr[t-i-1] = wrt;
    }

    return cstr;
}

size_t words(const char* cstr) {
    size_t t = length(cstr);
    int count = 0;

    for (int i = 0; i < t; i++) {
        if (!(isLetter(cstr[i])))
            if (isLetter(cstr[i+1]))
                count++;
    }
    return count;
}

size_t words2(const char* cstr) {
    size_t t = length(cstr);
    int count = 0;

    for (int i = 0; i < t; i++) {
        if (!(isLetter(cstr[i])))
            if (isLetter(cstr[i+1]) && isLetter(cstr[i+2]))
                count++;
    }
    return count;
}

char* contact(char* t, const char* s) {
    int size = length(t);

    for(int i = 0; i < length(s); i++){
        t[size+i] = s[i];
    }

    return t;
}