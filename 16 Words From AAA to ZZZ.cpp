// 16 Words From AAA to ZZZ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void WordsFromAAAtoZZZ() {
    string Word = "";
    for (short i = 65; i < 91; i++) {
        for (short j = 65; j < 91; j++) {
            for (short k = 65; k < 91; k++) {
                Word += char(i);
                Word += char(j);
                Word += char(k);
                cout << Word << endl;
                Word = "";
            }
        }
    }
}

int main()
{
    WordsFromAAAtoZZZ();
}

