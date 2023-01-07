// 40 Copy Distinct Numbers to Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    Arr[1] = 10;
    Arr[2] = 10;
    Arr[3] = 20;
    Arr[4] = 20;
    Arr[5] = 50;
    Arr[6] = 80;
    Arr[7] = 80;
    Arr[8] = 80;
    Arr[9] = 90;
}

short FindIndexNumber(short Arr[100], short ArrLength, short NumberToCheck) {

    for (short i = 0; i < ArrLength; i++) {
        if (Arr[i] == NumberToCheck)
            return i;
    }
    return -1;
}

bool isNumberInArray(short Arr[100], short ArrLength, short NumberToCheck) {
    return (FindIndexNumber(Arr, ArrLength, NumberToCheck) != -1);
}

void AddArrayElement(short Arr[100], short& ArrLength, short Number) {

    Arr[ArrLength] = Number;
    ArrLength++;
}

void CopyDistinctNumbers(short ArrSource[100], short ArrDestination[100], short ArrLength, short& Arr2Length) {

    for (short i = 0; i < ArrLength; i++) {
        if (!isNumberInArray(ArrDestination, Arr2Length, ArrSource[i]))
            AddArrayElement(ArrDestination, Arr2Length, ArrSource[i]);
    }

}

void PrintArray(short Arr[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    short ArrSource[100], ArrDestination[100], ArrLength = 0, Arr2Length = 0;

    FillArrayHardCoded(ArrSource, ArrLength);
    cout << "\nArray Elements: \n";
    PrintArray(ArrSource, ArrLength);
    cout << "\nArray Length: " << ArrLength << endl;

    CopyDistinctNumbers(ArrSource, ArrDestination, ArrLength, Arr2Length);
    cout << "\nArray Elements After Copy Distinct Numbers: \n";
    PrintArray(ArrDestination, Arr2Length);
    cout << "\nArray Length: " << Arr2Length << endl;

}