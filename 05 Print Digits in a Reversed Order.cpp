// 05 Print Digits in a Reversed Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void PrintDigits(short Number) {

    short Remainder = 0;
    while (Number > 0) {
        Remainder = Number % 10;
        Number = Number / 10;
        cout << Remainder << endl;
    }
}

int main()
{
    short Number = ReadPositiveNumber("Enter a Number: ");
    
    PrintDigits(Number);
}

