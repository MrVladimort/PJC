#include <iostream>

using namespace std;

size_t length(const char* cstr){
    int count = 0;

    while(cstr[count] != '\0')
        count++;

    return count;
}

char toUpper(char a){
    if(96 < a && a < 123)
        return a - 32;
    else
        return a;
}

class Letters {
public:
    int letters[26]{0};

    Letters(const char* text){
        int letter = 65;
        size_t sizetext = length(text);

        for(int i = 0; i < 26; i++) {
            int count = 0;
            for (int j = 0; j < sizetext; j++) {
                if ((char) letter == toUpper(text[j]))
                    count++;
            }
            this->letters[i] = count;
            letter++;
        }
    }

    int numOfDifferent(){
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(this->letters[i] != 0)
                count++;
        }
        return count;
    }

    char getMostFrequent(){
        int max, index;
        for(int i = 0; i < 26; i++){
            if(i == 0){
                max = this->letters[i];
                index = 0;
            }

            if(this->letters[i] > max){
                max = this->letters[i];
                index = i;
            }
        }

        return (char) 65 + index;
    }

    void printFrequencies(){
        int max;

        for (int i = 0; i < 26; i++) {
            if (i == 0)
                max = this->letters[i];

            else if (this->letters[i] > max)
                max = this->letters[i];
        }


        for (int i = max; i > 0; i--) {
            for (int j = 0; j < 26; j++) {
                    if (this->letters[j] >= i)
                        cout << "*";
                    else
                        cout << " ";
            }
            cout << endl;
        }

        for(int i = 0; i < 26; i++){
            cout << (char)(65 + i);
        }
        cout << endl;
    }

};



int main() {
    const char* text =
            "To be, or not to be- that is the questiona\n:"
                    "Whether 'tis nobler in the mind to suffer\n"
                    "The slings and arrows of outrageous fortune\n"
                    "Or to take arms against a sea of troubles,\n"
                    "And by opposing end them.";
    Letters lett(text);
    cout << "Most frequent letter: "
              << lett.getMostFrequent() << endl;
    cout << "Number of different letters: "
              << lett.numOfDifferent() << endl;
    cout << "Frequency table of all letters:\n";
    cout << endl;
    lett.printFrequencies();
}