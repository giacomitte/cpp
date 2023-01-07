// 08 Digit Frequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

short CountDigitFrequency(short Number, short DigitToCheck) {

    short Remainder = 0, FreqCount = 0;

    while (Number > 0) {
        Remainder = Number % 10;
        Number = Number / 10;
        if (Remainder == DigitToCheck)
            FreqCount++;
    }
    return FreqCount;
}

void PrintResult(short Number, short DigitToCheck) {

    cout << "Digit " << DigitToCheck << " Frequency is " << CountDigitFrequency(Number, DigitToCheck) << " Time(s)\n";
}

int main()
{
    short Number = ReadPositiveNumber("Enter a Positive Number: ");
    short DigitToCheck = ReadPositiveNumber("Enter a Digit to Check: ");

    PrintResult(Number, DigitToCheck);
}

