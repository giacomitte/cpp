// 41 Is Palindrome Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

short ReadPositiveNumber(string Message) {

    short Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void FillArrayHardCoded(short Arr[100], short& ArrLength) {
    ArrLength = 10;

    Arr[0] = 10;
    Arr[1] = 20;
    Arr[2] = 30;
    Arr[3] = 40;
    Arr[4] = 50;
    Arr[5] = 50;
    Arr[6] = 40;
    Arr[7] = 30;
    Arr[8] = 20;
    Arr[9] = 10;
}

void PrintArray(short Arr[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

bool isPalindromeArray(short Arr[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        if (Arr[i] != Arr[ArrLength - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    short Arr[100],  ArrLength = 0;

    FillArrayHardCoded(Arr, ArrLength);
    cout << "\nArray Elements: \n";
    PrintArray(Arr, ArrLength);

    if (isPalindromeArray(Arr, ArrLength)) 
        cout << "\nYes, The arry is a palindrome\n";
    else 
        cout << "\nNo, The arry is not a palindrome\n";

}