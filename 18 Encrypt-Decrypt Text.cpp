// 18 Encrypt-Decrypt Text.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string ReadText() {

    string Text;
    cout << "Enter a Text To Encrypt: ";
    getline(cin, Text);

    return Text;
}

string Encrypt(string Text, short EncryptionKey) {

    for (short i = 0; i < Text.length(); i++) {

        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}

string Decrypt(string Text, short EncryptionKey) {

    for (short i = 0; i < Text.length(); i++) {

        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

int main()
{
    const short EncryptionKey = 2;

    string Text = ReadText();
    string TextAfterEncryption = Encrypt(Text, EncryptionKey);
    string TextAfterDecryption = Decrypt(TextAfterEncryption, EncryptionKey);

    cout << "\nText Before Encryption: " << Text << endl;
    cout << "Text After Encryption: " << TextAfterEncryption << endl;
    cout << "Text After Decryption: " << TextAfterDecryption << endl;
}

