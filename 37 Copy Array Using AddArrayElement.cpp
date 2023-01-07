﻿// 37 Copy Array Using AddArrayElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

short ReadPositiveNumber(string Message) {

    short Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

short RandomNumber(short From, short To) {

    short Random = rand() % (To - From + 1) + From;

    return Random;
}

void FillArrayWithRandomNumbers(short Arr[100], short& ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        Arr[i] = RandomNumber(1, 100);
    }

}

void AddArrayElement(short Arr[100], short& ArrLength, short Number) {

    Arr[ArrLength] = Number;
    ArrLength++;
}

void CopyArrayUsingAddArrayElement(short ArrSource[100], short ArrDestination[100], short ArrLength, short &Arr2Length) {

    for (short i = 0; i < ArrLength; i++) {
        AddArrayElement(ArrDestination, Arr2Length, ArrSource[i]);
    }

}

void PrintArray(short Arr[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    //Seeds the random number generator in cpp, called only once
    srand((unsigned)time(NULL));

    short ArrSource[100], ArrDestination[100], ArrLength, Arr2Length = 0;

    ArrLength = ReadPositiveNumber("How Many Element Do You Want in Array? ");

    FillArrayWithRandomNumbers(ArrSource, ArrLength);
    cout << "\nArray Elements: \n";
    PrintArray(ArrSource, ArrLength);

    CopyArrayUsingAddArrayElement(ArrSource, ArrDestination, ArrLength, Arr2Length);
    cout << "\nArray Elements After Copy: \n";
    PrintArray(ArrDestination, Arr2Length);

    
}

