#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <stdio.h>

using namespace std;

clock_t start, stop;
double czas;

long double potega(int p, int w)
{
    if (w==0) return 1;
    else return p*potega(p, w-1);   // funkcja rekurencyjna
}

long double fib(int n)
{
    if (n==1 || n==2) return 1;
    else return fib(n-1)+fib(n-2);  // funkcja rekurencyjna
}

long double silnia(int n)
{
    if (n==0) return 1;
    else return n*silnia(n-1);  // funkcja rekurencyjna

}

int potega_p=2;
int potega_w=96;
long double potega_wynik=1;

int main()
{
    fstream txt_results;
    txt_results.open("results.txt", ios::out);

    start = clock();
    cout << "Potegowanie: " << potega(2,96) << endl;
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas obliczania (rekurencja): " << czas << " s" << endl;
    txt_results << "Potegowanie - czas obliczania (rekurencja): " << czas << " s" << endl;

    start = clock();
    while(potega_w>0)
    {
        potega_wynik *= potega_p;
        potega_w--;
    }
    cout << "Potegowanie: " << potega_wynik << endl;
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas obliczania (petla while): " << czas << " s" << endl;
    txt_results << "Potegowanie - czas obliczania (petla while): " << czas << " s" << endl;
    cout << endl;

    start = clock();
    cout << "Ciag Fibonacciego: " << fib(42) << endl;
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas obliczania (rekurencja): " << czas << " s" << endl;
    txt_results << "Ciag Fibonacciego - czas obliczania (rekurencja): " << czas << " s" << endl;
    cout << endl;

    start = clock();
    cout << "Silnia: " << silnia(100) << endl;
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas obliczania (rekurencja): " << czas << " s" << endl;
    txt_results << "Silnia - czas obliczania (rekurencja): " << czas << " s" << endl;

    txt_results.close();

    cout << endl;
    cout << endl;
    cout << "                  .txt file saved                   " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "              written in C++ by ReznoR              " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "          [Press Enter to close the program]        " << endl;

    getchar();

    return 0;
}
