#include <iostream>
#include <string>

using namespace std;

void rekur() {
    int a;

    cin >> a;

    if (a != 0) {
        rekur();
        cout << a << " ";
    }
}

void zad2() {
    int a, num, count = 1, countmax, numofmax;

    do {
        cin >> a;
        if(a == num) {
            count++;
        }else{
            if(count > countmax){
                countmax = count;
                numofmax = num;
            }
            count = 1;
        }
        num = a;
    } while (a != 0);

    cout << "Najdluzsza sekwencja: " << countmax << " razy liczba " << numofmax;
}

void zad3(){
    int a, countmin, numofmin, countmax, numofmax;

    cin >> a;
    while (a != 0) {
        if(a > numofmax){
            numofmax = a;
            countmax = 0;}
        if (a < numofmin){
            numofmin = a;
            countmin = 0;}
        if(a == numofmax)
            countmax++;
        if (a == numofmin)
            countmin++;
        cin >> a;
    }
    cout << "Min: " << numofmin << "; Wystapilo " << countmin << " razy" << endl;
    cout << "Max: " << numofmax << "; Wystapilo " << countmax << " razy" << endl;
}

bool isPrime(int n){
    if(n<2)
        return false; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą

    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza

    return true;
}

void printDivisors(int n){
    for(int i = 1; i <= n; i++){
        if(n%i == 0)
            cout << i << " ";
    }
    cout << endl;
}

int numDivisors(int n){

    int count = 0;

    for(int i = 1; i <= n; i++){
        if (n % i == 0)
            count = count + i;
    }

    return count;
}

int gdc(int m, int n){
    int max = m;
    int min = n;
    int maxdiv;

    if(n > m) {
        min = m;
        max = n;
    }
    for(int i = 1; i <= max; i++){
        if(max % i == 0) {
            if (min % i == 0)
                maxdiv = i;
        }
    }
    return  maxdiv;
}

int phi(int n){

    int count = n;

    if(isPrime(n))
        return n - 1;

    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            count -= count / i;
        }

    if (n > 1) count -= count / n;

    return count;
}

int main() {
    //rekur();
    //zad2();
    //zad3();
    //cout << isPrime(9) << endl;
    //printDivisors(21);
    //cout << numDivisors(21) << endl;
    //cout << gdc(9, 18) << endl;
    cout << phi(51) << endl;
}