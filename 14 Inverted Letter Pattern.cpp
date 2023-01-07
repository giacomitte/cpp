// 14 Inverted Letter Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void PrintInvertedLetterPattern(short Number) {

    for (short i = (Number + 65 - 1); i >= 65; i--) {
        for (short j = 65; j <= i; j++) {
            cout << char(i);
        }
        cout << endl;
    }
}

int main()
{
    short Number = ReadPositiveNumber("Enter a Positive Number: ");

    PrintInvertedLetterPattern(Number);
}

