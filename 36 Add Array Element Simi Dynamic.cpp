// 36 Add Array Element Simi Dynamic.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void AddArrayElement(short Arr[100], short& ArrLength, short Number) {

    Arr[ArrLength] = Number;
    ArrLength++;
}

void InputUserNumberInArray(short Arr[100], short& ArrLength) {

    bool AddMore = true;

    do {

        AddArrayElement(Arr, ArrLength, ReadPositiveNumber("Enter a Number: "));

        cout << "Do You Want Add More [0]No, [1]Yes? ";
        cin >> AddMore;
        
    } while (AddMore);

}

void PrintArray(short Arr[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    short Arr[100], ArrLength = 0;

    InputUserNumberInArray(Arr, ArrLength);
    cout << "\nArray Elements: ";
    PrintArray(Arr, ArrLength);

    cout << "\nArray Length: " << ArrLength << endl;
}

