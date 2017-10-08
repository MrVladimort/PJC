#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

 void zad1() {
	 int a, b, c;
	 cin >> a >> b >> c;
	 int des = b*b - 4 * a*c;
	 int sqrdes = sqrt(des);
	 int x1 = (-b - sqrdes) / (2 * a);
	 int x2 = (-b + sqrdes) / (2 * a);
	 cout << x1 << "  " << x2 << endl;
}

 void zad2() {
	 double wzrost, waga, bmi;
	 cout << "Wzrost?" << endl;
	 cin >> wzrost;
	 cout << "Waga?" << endl;
	 cin >> waga;

	 if (wzrost > 100)
		 wzrost = wzrost / 100;

	 bmi = waga / (sqrt(wzrost));

	 cout << "BMI: " << bmi << endl;
 }

 void zad3() {
	 int a, b, c, max, min;
	 cout << "Wpisac 3 liczby " << endl;
	 cout << "a = ";
	 cin >> a;
	 cout << "b = ";
	 cin >> b;
	 cout << "c = ";
	 cin >> c;

	 if (a > c && a > b)
		 max = a;
	 if (b > c && b > a)
		 max = b;
	 else
		 max = c;
	 cout << "Max: " << max << endl;

	 if (a < c && a < b)
		 min = a;
	 if (b < c && b < a)
		 min = b;
	 else
		 min = c;
	 cout << "Min: " << min << endl;
 }

 void zad4() {
	 int a, b, c, max;
	 bool wrt = true;

	 cout << "Liczby nieujemne" << endl;
	 cin >> a >> b >> c;

	 while (wrt) {
		 if (a >= 0 && b >= 0 && c >= 0) {
			 wrt = false;
			 break;
		 }
		 cin >> a >> b >> c;
	 }

     if(a > b && a > c)
         max = a;
     else if (b > a && b > c)
         max = b;
     else
         max = c;


     for(int i = max; i > 0; i--) {
         if (a >= i)
             cout << "*";
         else
             cout << " ";

         if (b >= i)
             cout << "*";
         else
             cout << " ";

         if (c >= i)
             cout << "*";
         else
             cout << " ";

         cout << endl;
     }
 }

 void zad5(){
     string s;
     int num, numb, max, numofmax;

     cout << "enter a natural number (0 if done): ";
     cin >> num;

     while(num != 0) {
         s = to_string(num);

         for(int i = 0; i < s.size(); i++){
             numb += s.at(i) - '0';
         }

         if (max < numb){
             max = numb;
             numofmax = num;
         }

         numb = 0;
         cout << "enter a natural number (0 if done): ";
         cin >> num;
     }
     cout << "Max sum of digits was " << max << " for " << numofmax << endl;
}

 void zad6() {
     long int min, max, num;
     int count = 0;
     char com;

     system("CLS");
     srand(time(0));

     min = 1;
     max = 1000000;
     num = (double) rand() / (RAND_MAX + 1) * (min - max) + max;


     while (count < 20) {
         cout << "Czy to jest " << num << "?" << endl;
         cin >> com;

         if (com == 's') {
             max = num-1;
             num = (double) rand() / (RAND_MAX + 1) * (min - max) + max;
         }

         if (com == 'b') {
             min = num+1;
             num = (double) rand() / (RAND_MAX + 1) * (min - max) + max;
         }

         if (com == 'y')
             break;

         count++;
     }

     if (com == 'y')
         cout << "Prawidlowa odpowiedz to " << num << endl << "Liczba zapytan to " << count << endl;
     else {
         cout << "Czy pomyslana liczba to " << num << "?" << endl << "Prosze wpisac prawidlowa odpowiedz ";
         cin >> num;
         cout << "Prawidlowa odpowiedz to " << num << endl << "Liczba zapytan to " << count << endl;
     }
 }


 int main() {
	 //cout << "Hello" << endl;
	 //zad1();
	 //zad2();
	 //zad3();
	 //zad4();
     //zad5();
     zad6();
 }