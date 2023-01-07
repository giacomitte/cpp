// 48 Floor Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber() {

    float Number;
    cout << "Enter a Number: ";
    cin >> Number;

    return Number;
}

short Floor(float Number) {

    if (Number > 0)
        return (int)Number;
    else
        return (int)--Number;
}

int main()
{
    float Number = ReadNumber();

    cout << "\nC++ Floor: " << floor(Number) << endl;
    cout << "\nMy Floor: " << Floor(Number) << endl;
}

