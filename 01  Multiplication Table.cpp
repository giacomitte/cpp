// Problem 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void PrintTableHeader() {

    cout << "\n\n";
    cout << "\t\t\tMultiplication Table From 1 to 10\n\n";
    for (short i = 1; i <= 10; i++) {
        cout << "\t" << i;
    }
    cout << "\n____________________________________________________________________________________\n";
}

string ColumnSeprator(short i) {
    if (i > 9)
        return "   |";
    else
        return "    |";
}

void PrintMultiplicationTable() {

    PrintTableHeader();
    for (short i = 1; i <= 10; i++) {
        cout << i << ColumnSeprator(i) << "\t";
        for (short j = 1; j <= 10; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

int main()
{
    PrintMultiplicationTable();
}

