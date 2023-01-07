// 04 Perfect Numbers From 1 to N.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

short ReadPositiveNumber(string Message) {
    short Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

bool isPerfect(short Number) {
    short Sum = 0;
    for (short i = 1; i < Number; i++) {
        if (Number % i == 0)
            Sum += i;
    }
    return Number == Sum;
}

void PrintPerfectNumbersFrom1ToN(short Number) {

    cout << "Perfect Numbers From 1 to " << Number << ": \n";
    for (short i = 1; i <= Number; i++) {
        if (isPerfect(i))
            cout << i << endl;
    }
}

int main()
{
    short Number = ReadPositiveNumber("Enter a Number: ");

    PrintPerfectNumbersFrom1ToN(Number);
}

