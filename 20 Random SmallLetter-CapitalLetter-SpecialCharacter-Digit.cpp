// 20 Random SmallLetter-CapitalLetter-SpecialCharacter-Digit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType {SmallLetter, CapitalLetter, SpecialCharacter, Digit};

short RandomNumber(short From, short To) {

    short Random = rand() % (To - From + 1) + From;

    return Random;
}

char GetRandomCharacter(enCharType CharType) {
    
    switch (CharType) {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
        case (enCharType::CapitalLetter):
            return char(RandomNumber(65, 90));
        case (enCharType::SpecialCharacter):
            return char(RandomNumber(33, 47));
        case (enCharType::Digit):
            return char(RandomNumber(48, 57));
    }
}

int main()
{
    //Seeds the random number generator in cpp, called only once.
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
    cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
    cout << GetRandomCharacter(enCharType::Digit) << endl;
}

