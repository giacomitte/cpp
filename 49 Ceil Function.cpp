// 49 Ceil Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

short Ceil(float Number) {

    float FractionPart = GetFractionPart(Number);

    if (abs(FractionPart) > 0) {
        if (Number > 0)
            return (int)++Number;
        else
            return (int)Number;
    }
    else {
        return (int)Number;
    }
        
}

int main()
{
    float Number = ReadNumber();

    cout << "\nC++ Ceil: " << ceil(Number) << endl;
    cout << "\nMy Ceil: " << Ceil(Number) << endl;
    
}

