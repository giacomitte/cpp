// 03 Perfect Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void PrintResult(short Number) {

    if (isPerfect(Number))
        cout << Number << " is Perfect Number\n";
    else
        cout << Number << " is Not Perfect Number\n";
}

int main()
{
    short Number = ReadPositiveNumber("Enter a Number: ");

    PrintResult(Number);

}

