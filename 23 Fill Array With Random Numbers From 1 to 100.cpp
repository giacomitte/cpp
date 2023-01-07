// 23 Fill Array With Random Numbers From 1 to 100.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

short RandomNumber(short From, short To) {

    short Random = rand() % (To - From + 1) + From;

    return Random;
}

short ReadPositiveNumber(string Message) {

    short Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void FillArrayWithRandomNumbers(short Arr[100], short& ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        Arr[i] =  RandomNumber(1, 100);
    }
    cout << endl;
}

void PrintArray(short Arr[100], short ArrLength) {

    cout << "\nArray Elements: ";
    for (short i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

int main()
{   
    //Seeds the random number generator in cpp, called only once
    srand((unsigned)time(NULL));

    short Arr[100], ArrLength;

    ArrLength = ReadPositiveNumber("How Many Elements Do You Want Add to Array? ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    PrintArray(Arr, ArrLength);
}

