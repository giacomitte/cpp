// Project2 Math Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

enum enQuestionLevel {Easy = 1, Medium = 2, Hard = 3, Mix = 4 };

enum enOperationType {Add = 1, Subtract = 2, Multiple = 3, Divide = 4, MixUp = 5};

struct stQuestion {
    short Number1 = 0;
    short Number2 = 0;
    enOperationType OperationType;
    enQuestionLevel QuestionLevel;
    short CorrectAnswer = 0;
    short PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuizz {
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool isPass = false;
};

short RandomNumber(short From, short To) {

    short Random = rand() % (To - From + 1) + From;

    return Random;
}

string GetOperationTypeSymbol(enOperationType OperationType) {
    switch (OperationType) {
    case enOperationType::Add:
        return "+";
    case enOperationType::Subtract:
        return "-";
    case enOperationType::Multiple:
        return "*";
    case enOperationType::Divide:
        return "/";
    default:
        return "Mix";
    }
}

string GetQuestionLevelText(enQuestionLevel QuestionLevel) {

    string ArrQuestionLevelText[4] = { "Esay", "Medium", "Hard", "Mix" };

    return ArrQuestionLevelText[QuestionLevel - 1];
}

void SetScreenColor(bool Right) {

    if (Right)
        system("color 2F");
    else {
        system("color 4F");
        cout << "\a";
    }
        
}

short ReadHowManyQuestions() {

    short NumberOfQuestions = 0;
    do {
        cout << "How Many Question Do You Want Answer? ";
        cin >> NumberOfQuestions;
    } while (NumberOfQuestions < 1 && NumberOfQuestions > 10);

    return NumberOfQuestions;
}

enQuestionLevel ReadQuestionLevel() {

    short QuestionLevel = 0;

    do {
        cout << "Enter Question Level [1]Easy, [2]Medium, [3]Hard, [4]Mix? ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);

    return (enQuestionLevel) QuestionLevel;
}

enOperationType ReadOperationType() {

    short OperationType;
    do {
        cout << "Enter Operation Type [1]Add, [2]Subtract, [3]Multiple, [4]Divide, [5]Mix: ";
        cin >> OperationType;
    } while (OperationType < 1 || OperationType > 5);

    return (enOperationType)OperationType;
}

int SimpleCalculator(short Number1, short Number2, enOperationType OperationType) {

    switch (OperationType) {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Subtract:
        return Number1 - Number2;
    case enOperationType::Multiple:
        return Number1 * Number2;
    case enOperationType::Divide:
        return Number1 / Number2;
    default:
        return Number1 + Number2;
    }
}

enOperationType GetRandomOperationType() {

    short OperationType = RandomNumber(1, 4);

    return (enOperationType)OperationType;
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OperationType) {

    stQuestion Question;

    if (QuestionLevel == enQuestionLevel::Mix) {
        QuestionLevel = (enQuestionLevel) RandomNumber(1, 3);
    }

    if (OperationType == enOperationType::MixUp) {
        OperationType = GetRandomOperationType();
    }

    Question.OperationType = OperationType;

    switch (QuestionLevel) {
    case enQuestionLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionLevel::Medium:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;
      
    }
    return Question;
}

void GenerateQuizzQuestions(stQuizz &Quizz) {

    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++) {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OperationType);
    }
}

short ReadQuestionAnswer() {

    short Answer = 0;
    cin >> Answer;
    return Answer;
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber) {

    cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOperationTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
    cout << "\n____________\n";
}

void CorrectQuestionAnswer(stQuizz& Quizz, short QuestionNumber) {

    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer) {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswers++;
        cout << "\nWrong Answer\n";
        cout << "Correct Answer: " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << endl;
    }
    else {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswers++;
        cout << "\nRight Answer\n";
    }
    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz) {

    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {
        PrintTheQuestion(Quizz, QuestionNumber);
        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
        CorrectQuestionAnswer(Quizz, QuestionNumber);
    }
    Quizz.isPass = Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers;
}

string GetFinalResultsText(bool Pass) {
    if (Pass)
        return "Pass :)\n";
    else
        return "Fail :(\n";
}

void PrintQuizzResults(stQuizz Quizz) {

    cout << "\n_____________________________________\n\n";
    cout << "Final Results is: " << GetFinalResultsText(Quizz.isPass);
    cout << "\n_____________________________________\n";
    cout << "\nNumber Of Questions    : " << Quizz.NumberOfQuestions;
    cout << "\nQuestion Level         : " << GetQuestionLevelText(Quizz.QuestionLevel);
    cout << "\nOperation Type         : " << GetOperationTypeSymbol(Quizz.OperationType);
    cout << "\nNumber Of Right Answers: " << Quizz.NumberOfRightAnswers;
    cout << "\nNumber Of Wrong Answers: " << Quizz.NumberOfWrongAnswers;
    cout << "\n_____________________________________\n\n";
}

void PlayMathGame() {

    stQuizz Quizz;

    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.QuestionLevel = ReadQuestionLevel();
    Quizz.OperationType = ReadOperationType();

    GenerateQuizzQuestions(Quizz);
    AskAndCorrectQuestionListAnswers(Quizz);
    PrintQuizzResults(Quizz);

}

void ResetScreen() {
    system("cls");
    system("color 0F");
}

void StartGame() {

    char PlayAgain = 'Y';

    do {

        ResetScreen();
        PlayMathGame();

        cout << "Do You Want Play Again Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');

}

int main()
{
    //Seeds the random number generator in cpp called only once
    srand((unsigned)time(NULL));

    StartGame();

}


