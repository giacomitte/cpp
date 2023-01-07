// 21 Generate Keys.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

char GetRandomCharacter(enCharType CharType) {

    switch (CharType) {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));
        case enCharType::Digit:
            return char(RandomNumber(48, 57));
    }
}

string GenerateWord(enCharType CharType, short Length) {

    string Word = "";
    for (short i = 0; i < Length; i++) {
        Word += GetRandomCharacter(CharType);
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

void GenerateKeys(short NumberOfKeys) {

    for (short i = 0; i < NumberOfKeys; i++) {
        cout << "Key[" << i + 1 <<"]: " << GenerateKey() << endl;
    }
}

int main()
{
    //Seeds the random number generator in cpp, called only once
    srand((unsigned)time(NULL));

    short NumberOfKeys = ReadPositiveNumber("Enter how many keys to generate: ");

    GenerateKeys(NumberOfKeys);
}

