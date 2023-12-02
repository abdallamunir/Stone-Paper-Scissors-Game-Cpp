#pragma once
#include <iostream>
using namespace std;

// prompts
// "How many rounds 1 to 10?"
//Round [] begins:
// Your choice: [1]:Stone, [2]:Paper, [3]:Scissors ?
// ------------------Round  [1]----------------------
//Player1   choice: Stone
//Computer  choice: Stone
//Round Winner    : [No Winner]
//----------------------------------------------------
//
//----------------------------------------------------
//                  +++ G a m e  O v e r +++
// ---------------------------------------------------
// ------------------ [Game Results] -----------------
// Game Rounds          : 3
// Player1 won times    : 0
// Computer won times   : 0
// Draw times           : 3
// Final Winner         : No Winner
// ---------------------------------------------------
// Do you want to play again? Y/N? 

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};


//=======================================

string WinnerName(enWinner Winner);

enWinner WhoWonTheRound(stRoundInfo RoundInfo);

string ChoiceName(enGameChoice Choice);

void SetWinnerScreenColor(enWinner Winner);

void PrintRoundResults(stRoundInfo RoundInfo);

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes);

stGameResults FillGameResults(int GameRounds, short Player1WinTimes,
    short ComputerWinTimes, short DrawTimes);

enGameChoice ReadPlayerChoice();

enGameChoice GetComputerChoice();

stGameResults PlayGame(short HowManyRounds);

void ShowGameOverScreen();

void ShowFinalGameResults(stGameResults GameResults);

short ReadHowManyRounds();

void ResetScreen();
void StartGame();
std::string Tabs(short NumberOfTabs);

std::string Tabs(short NumberOfTabs);

int RandomNumberInRange(int From, int To);
