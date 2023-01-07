// 30 Sum Of 2 Arrays to a Third One.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void SumOfTwoArrays(short Arr[100], short Arr2[100], short ArrSum[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        ArrSum[i] = Arr[i] + Arr2[i];
    }
}

int main()
{
    //Seeds the random number generator in cpp, called only once
    srand((unsigned)time(NULL));

    short Arr[100], Arr2[100], ArrSum[100], ArrLength;

    ArrLength = ReadPositiveNumber("Enter How Many Elements Do You Want in Array: ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    cout << "\nArray1 Elements: \n";
    PrintArray(Arr, ArrLength);

    FillArrayWithRandomNumbers(Arr2, ArrLength);
    cout << "\nArray2 Elements: \n";
    PrintArray(Arr2, ArrLength);

    SumOfTwoArrays(Arr, Arr2, ArrSum, ArrLength);
    cout << "\n\nSum Of Array1 & Array2 Elements: \n";
    PrintArray(ArrSum, ArrLength);
}