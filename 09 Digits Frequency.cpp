// 09 Digits Frequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

short CountDigitFrequency(short Number, short FreqDigit) {

    short Remainder = 0, FreqCount = 0;

    while (Number > 0) {
        Remainder = Number % 10;
        Number = Number / 10;
        if (Remainder == FreqDigit)
            FreqCount++;
    }

    return FreqCount;
}

void PrintDigitsFrequency(short Number) {

    short DigitFrequency = 0;

    for (short i = 0; i < 10; i++) {

        DigitFrequency = CountDigitFrequency(Number, i);

        if (DigitFrequency > 0)
            cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s)" << endl;
    }
}

int main()
{
    short Number = ReadPositiveNumber("Enter a Positive Number: ");

    PrintDigitsFrequency(Number);
}

