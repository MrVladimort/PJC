#include <iostream>
using namespace std;

size_t length(const char* cstr) {
    int count = 0;

    while(cstr[count] != '\0')
        count++;

    return count;
}
bool HaveNonZnak(const char* a, size_t size){
    for(int i = 0; i < size; i++) {
        if (!(31 < a[i] && a[i] < 127)){
            cout << "Unresolved characters" << endl;
            return false;
        }
    }
    return true;
}
bool HaveNumber(const char* a, size_t size){
    for(int i = 0; i < size; i++){
        if (47 < a[i] && a[i] < 58)
            return true;
    }
    cout << "No digit" << endl;
    return false;
}
bool HaveUpper(const char* a, size_t size){
    for(int i = 0; i < size; i++) {
        if(64 < a[i] && a[i] < 91)
            return true;
        }
    cout << "No upper letter" << endl;
    return false;
}
bool HaveLower(const char* a, size_t size){
    for(int i = 0; i < size; i++) {
        if(96 < a[i] && a[i] < 123)
            return true;
        }
    cout << "No lower letter" << endl;
    return false;
}
bool HaveNonAlphanumeric(const char* a, size_t size){
    for(int i = 0; i < size; i++) {
        if(!(47 < a[i] && a[i] < 58) && !(64 < a[i] && a[i] < 91) && !(96 < a[i] && a[i] < 123))
            return true;
    }
    cout << "No non-alphanumeric character" << endl;
    return false;
}
bool DifferentCharacters(const char* a, size_t size){
    int kek = 0;
    for(int i = 0; i < size; i++){
        int count = 0;
        for(int j = 0; j < size; j++){
            if(a[i] == a[j])
                count++;
        }
        if(count >= 2)
            kek++;
    }

    if(kek > size/2) {
        cout << "Too few different characters" << endl;
        return false;
    }

    return true;
}

bool checkpass(const char* pass) {
    bool norm = true;
    size_t size = length(pass);

    if(size < 8) {
        norm = false;
        cout << "Too short" << endl;
    }

    if(!HaveNonZnak(pass, size))
        norm = false;
    if(!HaveNumber(pass, size))
        norm = false;
    if(!HaveUpper(pass, size))
        norm = false;
    if(!HaveLower(pass, size))
        norm = false;
    if(!HaveNonAlphanumeric(pass, size))
        norm = false;
    if(!DifferentCharacters(pass, size))
        norm = false;

    return norm;
}

int main() {
    const char* passes[] =
            {
                    "AbcDe93", "A1b:A1b>", "Ab:Acb<",
                    "abc123><", "Zorro@123", nullptr
            };
    for (int i = 0; passes[i] != nullptr; ++i) {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i])) cout << "OK" << endl;
        cout << endl;
    }
}