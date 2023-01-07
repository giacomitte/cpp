// 06 Sum of Digits.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

short SumOfDigits(short Number) {

    short Sum = 0, Remainder = 0;

    while (Number > 0) {
        Remainder = Number % 10;
        Number = Number / 10;
        Sum += Remainder;
    }
    return Sum;
}

void PrintResult(short Number) {

    cout << "Sum of Inserted Digits: " << SumOfDigits(Number) << endl;
}

int main()
{
    short Number = ReadPositiveNumber("Enter a Number: ");

    PrintResult(Number);
}

