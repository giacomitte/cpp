// 42 Count Odd Numbers in Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

short CountOddNumbers(short Arr[100], short ArrLength) {
    short Counter = 0;
    for (short i = 0; i < ArrLength; i++) {
        if (Arr[i] % 2 != 0)
            Counter++;
    }
    return Counter;
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

    short Arr[100], ArrLength;

    ArrLength = ReadPositiveNumber("How Many Element Do You Want in Array? ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    cout << "\nArray Elements: \n";
    PrintArray(Arr, ArrLength);
    
    cout << "\nOdd Numbers Count in Array: " << CountOddNumbers(Arr, ArrLength) << endl;

}