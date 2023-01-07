// 28 Copy Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

    for (short i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

void CopyArray(short ArrSource[100], short ArrDestination[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        ArrDestination[i] = ArrSource[i];
    }
}

int main()
{
    //Seeds the random number generator in cpp, called only once
    srand((unsigned)time(NULL));

    short ArrSource[100], ArrDestination[100], ArrLength;

    ArrLength = ReadPositiveNumber("Enter How Many Elements Do You Want in Array: ");

    FillArrayWithRandomNumbers(ArrSource, ArrLength);
    cout << "\nOriginal Array: ";
    PrintArray(ArrSource, ArrLength);

    CopyArray(ArrSource, ArrDestination, ArrLength);
    cout << "\nCopied Array: ";
    PrintArray(ArrDestination, ArrLength);

}