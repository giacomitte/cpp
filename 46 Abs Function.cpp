// 46 Abs Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

float Abs(float Number) {
    if (Number < 0)
        return -Number;
    else
        return Number;
}

int main()
{
    float Number = ReadNumber();

    cout << "\nC++ Abs: " << abs(Number) << endl;
    cout << "\nMy Abs: " << Abs(Number) << endl;
}

