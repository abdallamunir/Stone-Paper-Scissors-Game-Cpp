#include "StonePaperScissorsGame.h"
#include <iostream>

int RandomNumberInRange(int From, int To)
{
	//function to generate random number

	int randNum = std::rand() % (To - From + 1) + From;
	return randNum;
}


string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1","Computer","No Winner" };

	return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return Draw;
	}
	switch (RoundInfo.Player1Choice)
	{
	case Stone:
		if (RoundInfo.ComputerChoice == Paper)
		{
			return Computer;
		}
		break;
	case Paper:
		if (RoundInfo.ComputerChoice == Scissors)
		{
			return Computer;
		}
		break;
	case Scissors:
		if (RoundInfo.ComputerChoice == Stone)
		{
			return Computer;
		}
		break;
	}
	// if you reach here player 1 is winner

	return Player1;
}

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone","Paper","Scissors" };
	return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case Player1:
		system("color 2F");
		break;
	case Computer:
		system("color 4F");
		break;
	case Draw:
		system("color 6F");
		break;
	}
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n----------------Round [" << RoundInfo.RoundNumber <<
		"-------------------\n\n";
	cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << "\n";
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << "\n";
	cout << "Round Winner     : [" << RoundInfo.WinnerName << "]\n";
	cout << "------------------------------------------------\n";
	SetWinnerScreenColor(RoundInfo.Winner);

}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return Player1;
	else if (ComputerWinTimes > Player1WinTimes)
		return Computer;
	else
		return Draw;
}

stGameResults FillGameResults(int GameRounds, short Player1WinTimes,
	short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;
	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

enGameChoice ReadPlayerChoice()
{
	short Choice = 1;
	do
	{
		cout << "Your choice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
		cin >> Choice;
	} while (Choice < 1 || Choice >3);
	return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumberInRange(1, 3);
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		// increse win/draw counters
		if (RoundInfo.Winner == Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;
		PrintRoundResults(RoundInfo);
	}
	return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

void ShowGameOverScreen()
{
	cout << Tabs(2) <<
		"----------------------------------------------------\n\n";
	cout << Tabs(2) << "                       +++ G a m e  O v e r +++\n";
	cout << Tabs(2) <<
		"----------------------------------------------------\n\n";

}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "------------------ [Game Results]----------------------\n\n";
	cout << Tabs(2) << "Game Round         : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 Won Times  : " << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer Won Times : " << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw Times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;

	cout << Tabs(2) << "-------------------------------------------------------\n\n";
	SetWinnerScreenColor(GameResults.GameWinner);
}

short ReadHowManyRounds()
{
	short GameRounds = 1;

	do
	{
		cout << "How many rounds 1 to 10?  ";
		cin >> GameRounds;
	} while (GameRounds < 1 || GameRounds>10);
	return GameRounds;
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

std::string Tabs(short NumberOfTabs)
{
	string Tabs = "";
	for (int i = 0; i < NumberOfTabs; i++)
	{
		Tabs += "\t";
		cout << Tabs;
	}
	return Tabs;
}
