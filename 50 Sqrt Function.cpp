// 50 Sqrt Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

float Sqrt(float Number) {

    return pow(Number, 0.5);
}

int main()
{
    float Number = ReadNumber();

    cout << "\nC++ Sqrt: " << sqrt(Number) << endl;
    cout << "\nMy Sqrt: " << Sqrt(Number) << endl;

}

