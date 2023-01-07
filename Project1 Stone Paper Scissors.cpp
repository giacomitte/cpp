// Project1 Stone Paper Scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo {
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults {
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

short RandomNumber(short From, short To) {
    short Random = rand() % (To - From + 1) + From;

    return Random;

}

string WinnerName(enWinner Winner) {
    string ArrWinnerName[3] = { "Player", "Computer", "No Winner" };

    return ArrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo) {

    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.PlayerChoice) {

    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
            return enWinner::Computer;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
            return enWinner::Computer;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
            return enWinner::Computer;
    }
    
    return enWinner::Player;
}

string ChoiceName(enGameChoice GameChoice) {
    string ArrChoiceName[3] = {"Stone", "Paper", "Scissors"};

    return ArrChoiceName[GameChoice - 1];
}

void SetWinnerScreenColor(enWinner Winner) {
    switch (Winner) {
    case enWinner::Player:
        system("color 2f");
        break;
    case enWinner::Computer:
        system("color 4f");
        system("\a");
        break;
    case enWinner::Draw:
        system("color 6f");

    }
}

void PrintRoundResult(stRoundInfo RoundInfo) {
    cout << "\n______________Round [" << RoundInfo.RoundNumber << "]______________\n\n";
    cout << "Player Choice: [" << RoundInfo.PlayerChoice << "]\n";
    cout << "Computer Choice: [" << RoundInfo.ComputerChoice << "]\n";
    cout << "Who Won The Round: [" << RoundInfo.WinnerName << "]\n";
    cout << "_____________________________________\n\n";
    return SetWinnerScreenColor(RoundInfo.Winner);
    
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes) {

    if (PlayerWinTimes > ComputerWinTimes)
        return enWinner::Player;
    else if (ComputerWinTimes > PlayerWinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResults(short GameRounds, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes) {

    stGameResults GameResults;

    GameResults.GameRounds = GameRounds;
    GameResults.PlayerWinTimes = PlayerWinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(PlayerWinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);

    return GameResults;
}

enGameChoice ReadPlayerChoice() {

    short Choice = 1;
    do {
        cout << "\nYou Choice [1]Stone, [2]Paper, [3]Scissors: ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);

    return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice() {

    return (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRounds) {

    stRoundInfo RoundInfo;

    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++) {

        cout << "\nRound [" << GameRound << "] begins:";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player)
            PlayerWinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResult(RoundInfo);
    }

    return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs) {

    string t = "";

    for (short i = 1; i < NumberOfTabs; i++) {
        t += "\t";
        cout << t;
    }
    return t;
}

void ShowGameOverScreen() {

    short TabNumber = 2;
    cout << Tabs(TabNumber) << "_______________________________________________________\n\n";
    cout << Tabs(TabNumber) << "                        Game Over                      \n\n";
    cout << Tabs(TabNumber) << "_______________________________________________________\n\n";

}

void ShowFinalGameResults(stGameResults GameResults) {

    short TabNumber = 2;

    cout << Tabs(TabNumber) << "______________________[Game Results]___________________\n\n";
    cout << Tabs(TabNumber) << "Game Rounds: [" << GameResults.GameRounds << "]\n";
    cout << Tabs(TabNumber) << "Player Win Times: [" << GameResults.PlayerWinTimes << "]\n";
    cout << Tabs(TabNumber) << "Computer Win Times: [" << GameResults.ComputerWinTimes << "]\n";
    cout << Tabs(TabNumber) << "Draw Times: [" << GameResults.DrawTimes << "]\n";
    cout << Tabs(TabNumber) << "Final Winner: [" << GameResults.WinnerName << "]\n";

    SetWinnerScreenColor(GameResults.GameWinner);
}

short ReadHowManyRound() {

    short RoundGame = 1;
    do {
        cout << "Enter How Many Rounds: ";
        cin >> RoundGame;
    } while (RoundGame < 1 || RoundGame > 10);

    return RoundGame;
}

void ResetScreen() {

    system("cls");
    system("color 0f");
}

void StartGame() {

    char PlayAgain = 'Y';

    do {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRound());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);

        cout << "\n" << Tabs(3) << "Do You Want Play Again Y/N?";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');

}

int main()
{
    srand((unsigned)time(NULL));


    StartGame();
}

