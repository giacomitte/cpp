// 22 Repeated Elements Count in Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

short ReadPositiveNumber(string Message) {

    short Number;
    do {
        cout << Message;
        cin >> Number;
    } while(Number <= 0);

    return Number;
}

void ReadArray(short Arr[100], short &ArrLength) {

    cout << "\nEnter Array Elements\n";
    for (short i = 0; i < ArrLength; i++) {
        cout << "Element [" << i + 1 << "]: ";
        cin >> Arr[i];
    }
    cout << endl;
}

void PrintArray(short Arr[100], short ArrLength) {

    cout << "\nArray Elements: ";
    for (short i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << "\n\n";
}

short TimesRepeated(short Arr[100], short ArrLength, short NumberToCheck) {

    short Counter = 0;
    for (short i = 0; i < ArrLength; i++) {
        if (Arr[i] == NumberToCheck)
            Counter++;
    }
    return Counter;
}

int main()
{
    short Arr[100], ArrLength;

    ArrLength = ReadPositiveNumber("Enter How Many ELements Do You Want To Add? ");

    ReadArray(Arr, ArrLength);
    PrintArray(Arr, ArrLength);

    short NumberToCheck = ReadPositiveNumber("Enter a Number to Check: ");

    cout << "\nNumber (" << NumberToCheck << ") is Repeated ";
    cout << TimesRepeated(Arr, ArrLength, NumberToCheck) << " Time(s)\n";
}

