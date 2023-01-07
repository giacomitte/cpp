// 47  Round Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

float GetFractionPart(float Number) {

    return Number - (int)Number;
}

short Round(float Number) {
    short IntPart = (int)Number;

    float FractionPart = GetFractionPart(Number);
    if (abs(FractionPart) >= 0.5) {
        if (Number > 0)
            return ++IntPart;
        else
            return --IntPart;
    }
    else {
        return IntPart;
    }
}

int main()
{
    float Number = ReadNumber();

    cout << "\nC++ round: " << round(Number) << endl;
    cout << "\nMy Round: " << Round(Number) << endl;
}

