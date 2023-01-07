// 27 Average Of Random Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

short SumArray(short Arr[100], short ArrLength) {

    short Sum = 0;
    for (short i = 0; i < ArrLength; i++) {
        Sum += Arr[i];
    }
    return Sum;
}

float AverageArray(short Arr[100], short ArrLength) {

    return (float)SumArray(Arr, ArrLength) / ArrLength;
}

int main()
{
    //Seeds the random number generator in cpp, called only once
    srand((unsigned)time(NULL));

    short Arr[100], ArrLength, Sum;
    float Average;

    ArrLength = ReadPositiveNumber("Enter How Many Elements Do You Want in Array: ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    PrintArray(Arr, ArrLength);

    Sum = SumArray(Arr, ArrLength);
    cout << "\nSum Of Array: " << Sum << endl;

    Average = AverageArray(Arr, ArrLength);
    cout << "\nAverage Of Array: " << Average << endl;

    //Another Way
    cout << "\nAverage Of Array: " << (float)Sum / ArrLength << endl;

}