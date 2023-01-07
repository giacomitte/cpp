// 02 Print All Prime Numbers From 1 to N.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum enPrimeNotPrime { Prime, NotPrime };

short ReadPositiveNumber(string Message) {

    short Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

enPrimeNotPrime CheckPrime(short Number) {
    
    short M = round(Number / 2);
    for (short i = 2; i <= M; i++) {
        if (Number % i == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

void PrintAllPrimeNumbersFrom1ToN(short Number) {

    cout << "Prime Numbers From 1 to " << Number << ": \n";
    for (short i = 1; i <= Number; i++) {
        if (CheckPrime(i) == enPrimeNotPrime::Prime)
            cout << i << endl;
    }
}

int main()
{
    short Number = ReadPositiveNumber("Enter a Number: ");

    PrintAllPrimeNumbersFrom1ToN(Number);
    
}

