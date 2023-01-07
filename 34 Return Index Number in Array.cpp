// 34 Return Index Number in Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
        Arr[i] = RandomNumber(1, 100);
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

short FindIndexNumber(short Arr[100], short ArrLength, short NumberToCheck) {

    for (short i = 0; i < ArrLength; i++) {
        if (Arr[i] == NumberToCheck)
            return i;
    }
    return -1;
}

int main()
{
    //Seeds the random number generator in cpp, called only once
    srand((unsigned)time(NULL));

    short Arr[100], ArrLength, NumberToCheck, Index;

    ArrLength = ReadPositiveNumber("How Many Elements Do You Want Add to Array? ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    PrintArray(Arr, ArrLength);

    NumberToCheck = ReadPositiveNumber("\nEnter a Number to Check? ");
    Index = FindIndexNumber(Arr, ArrLength, NumberToCheck);

    cout << "\nNumber You Are Looking For: " << NumberToCheck << endl;
    if (Index == -1) {
        cout << "The Number Not Found" << endl;
    }
    else {
        cout << "The Number Found at Position: " << Index << endl;
        cout << "The Number Found at Order: " << Index + 1 << endl;
    }
}