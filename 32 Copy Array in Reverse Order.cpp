// 32 Copy Array in Reverse Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void PrintArray(short Arr[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
}

void CopyArrayInReverseOrder(short ArrSource[100], short ArrDestination[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        ArrDestination[i] = ArrSource[ArrLength -1 - i];
    }
}

int main()
{
    //Seeds the random numbers generators in cpp, called only once
    srand((unsigned)time(NULL));

    short ArrSource[100], ArrDestination[100], ArrLength;

    ArrLength = ReadPositiveNumber("Enter How Many Elements Do You Want To Add: ");

    FillArrayWithRandomNumbers(ArrSource, ArrLength);
    cout << "\nArray Elements: \n";
    PrintArray(ArrSource, ArrLength);

    CopyArrayInReverseOrder(ArrSource, ArrDestination, ArrLength);
    cout << "\n\nArray Elements After Copy in Reverse Order: \n";
    PrintArray(ArrDestination, ArrLength);
}

