// 33 Fill Array With Keys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType {SmallLetter, CapitalLetter, SpecialCharacter, Digit};

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

 char GetCharacterLetter(enCharType CharType) {

     switch (CharType) {
         case enCharType::CapitalLetter:
             return char(RandomNumber(65, 90));
         case enCharType::SmallLetter:
             return char(RandomNumber(97, 122));
         case enCharType::SpecialCharacter:
             return char(RandomNumber(33, 47));
         case enCharType::Digit:
             return char(RandomNumber(48, 57));
     }
}

 string GenerateWord(enCharType CharType, short Length) {

     string Word = "";
     for (short i = 0; i < Length; i++) {
         Word += GetCharacterLetter(CharType);
     }

     return Word;
 }

 string GenerateKey() {

     string Key = "";

     Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
     Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
     Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
     Key += GenerateWord(enCharType::CapitalLetter, 4);

     return Key;
 }

void FillArrayWithKeys(string Arr[100], short& ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        Arr[i] = GenerateKey();
    }
}

void PrintStringArray(string Arr[100], short ArrLength) {

    for (short i = 0; i < ArrLength; i++) {
        cout << "Array[" << i << "]: " << Arr[i] << endl;
    }
}

int main()
{
    //Seeds the random numbers generators in cpp, called only once
    srand((unsigned)time(NULL));

    string Arr[100];
    short ArrLength;

    ArrLength = ReadPositiveNumber("Enter How Many Keys Do You Want To Generate: ");

    FillArrayWithKeys(Arr, ArrLength);
    cout << "\nArray Keys: \n";
    PrintStringArray(Arr, ArrLength);

}
