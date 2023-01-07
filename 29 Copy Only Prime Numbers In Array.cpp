// 29 Copy Only Prime Numbers In Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

enum enPrimeNotPrime {Prime, NotPrime};

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

enPrimeNotPrime CheckPrime(short Number) {

    short M = round(Number / 2);
    for (short i = 2; i <= M; i++) {
        if (Number % i == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
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

void CopyPrimeNumbersInArray(short ArrSource[100], short ArrDestination[100], short ArrLength, short &Arr2Length) {

    short Counter = 0;
    for (short i = 0; i < ArrLength; i++) {
        if (CheckPrime(ArrSource[i]) == enPrimeNotPrime::Prime) {
            ArrDestination[Counter] = ArrSource[i];
            Counter++;
        }
    }

    Arr2Length = --Counter;
}

int main()
{
    //Seeds the random number generator in cpp, called only once
    srand((unsigned)time(NULL));

    short ArrSource[100], ArrDestination[100], ArrLength, Arr2Length = 0;

    ArrLength = ReadPositiveNumber("Enter How Many Elements Do You Want in Array: ");

    FillArrayWithRandomNumbers(ArrSource, ArrLength);
    cout << "\nOriginal Array: ";
    PrintArray(ArrSource, ArrLength);

    CopyPrimeNumbersInArray(ArrSource, ArrDestination, ArrLength, Arr2Length);
    cout << "\nPrime Numbers in Array Length: " << Arr2Length;
    cout << "\n\nPrime Numbers in Array: ";
    PrintArray(ArrDestination, Arr2Length);

}