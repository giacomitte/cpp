// 13 Number Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void PrintNumberPattern(short Number) {

    for (short i = 1; i <= Number; i++) {
        for (short j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
}

int main()
{
    short Number = ReadPositiveNumber("Enter a Positive Number: ");

    PrintNumberPattern(Number);
}

