// 31 Shuffle Ordered Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void Swap(short &A, short &B) {

    short Temp;

    Temp = A;
    A = B;
    B = Temp;
}

void FillArrayWithOrderedNumbers(short Arr[100], short &ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        Arr[i] = i + 1;
    }
}

void PrintArray(short Arr[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
}

void ShuffleArray(short Arr[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
    }
}

int main()
{
    //Seeds the random numbers generators in cpp, called only once
    srand((unsigned)time(NULL));

    short Arr[100], ArrLength;

    ArrLength = ReadPositiveNumber("Enter How Many Elements Do You Want To Add: ");

    FillArrayWithOrderedNumbers(Arr, ArrLength);
    cout << "\nArray Elements: \n";
    PrintArray(Arr, ArrLength);

    ShuffleArray(Arr, ArrLength);
    cout << "\n\nArray Elements After Shuffle: \n";
    PrintArray(Arr, ArrLength);
}

