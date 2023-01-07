// 17 Guess a 3 Letter Password.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

string ReadPassword() {
    string Password;

    cout << "Enter a 3 Letter Password (All Capital Letters): ";
    cin >> Password;

    return Password;
}

bool GuessPassword(string Password) {

    short Counter = 0;
    string Word = "";

    for (short i = 65; i <= 91; i++) {
        for (short j = 65; j <= 91; j++) {
            for (short k = 65; k <= 91; k++) {

                Counter++;

                Word += char(i);
                Word += char(j);
                Word += char(k);

                cout << "Trial ["<< Counter << "]: " << Word << endl;

                if (Word == Password) {
                    cout << "\nPassword is: " << Word << endl;
                    cout << "Found After " << Counter << " Trial(s)\n";
                    return true;
                }
                Word = "";
                
            }
        }
    }
}

int main()
{
    string Password = ReadPassword();

    GuessPassword(Password);
}

