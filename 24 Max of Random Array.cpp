// 24 Max of Random Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

short MaxNumberInArray(short Arr[100], short ArrLength) {

    short Max = Arr[0];
    for (short i = 0; i < ArrLength; i++) {
        if (Arr[i] > Max)
            Max = Arr[i];
    }
    return Max;
}

int main()
{
    //Seeds the random number generator in cpp, called only once
    srand((unsigned)time(NULL));

    short Arr[100], ArrLength, Max;

    ArrLength = ReadPositiveNumber("Enter How Many Elements Do You Want in Array: ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    PrintArray(Arr, ArrLength);

    Max = MaxNumberInArray(Arr, ArrLength);
    cout << "\nMax Number in Array: " << Max << endl;
}
