// 19 Random Number From N to M.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

short RandomNumber(short From, short To) {

    short Random = rand() % (To - From + 1) + From;

    return Random;
}

int main()
{
    //Seeds the random number generator in cpp, called only once. 
    srand((unsigned)time(NULL));

    cout << RandomNumber(1, 10);
}

