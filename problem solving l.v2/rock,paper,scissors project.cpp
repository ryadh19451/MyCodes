#include <iostream>
using namespace std;
enum enGameChoice { stone = 1, paper = 2, scissors = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };
struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice PlayerChoice;
	enGameChoice Computerchoice;
	enWinner Winner;
	string WinnerName;
};
struct stGameResults
{
	short GameRounds = 0;
	short PlayerWinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};
int randomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
string WinnerName(enWinner Winner)
{
	string arrWinnername[3] = { "Player", "Computer", "Draw" };
	return arrWinnername[Winner - 1];
}
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.Computerchoice)
	{
		return enWinner::Draw;
	}
	switch (RoundInfo.PlayerChoice)
	{
	case enGameChoice::stone:
		if (RoundInfo.Computerchoice == enGameChoice::paper)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::paper:
		if (RoundInfo.Computerchoice == enGameChoice::scissors)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::scissors:
		if (RoundInfo.Computerchoice == enGameChoice::stone)
		{
			return enWinner::Computer;
		}
		break;
	}
	return enWinner::Player;
}
string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
	return arrGameChoices[Choice - 1];
}
void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player:
		system("color 2F");
		break;
	case enWinner::Computer:
		system("color 4F");
		break;
	default:
		system("color 6F");
		break;
	}
}
void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n___________Round[" << RoundInfo.RoundNumber << "]___________\n\n";
	cout << "Player Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.Computerchoice) << endl;
	cout << "Round Winner   :   [" << RoundInfo.WinnerName << "]\n";
	cout << "____________________________________________________\n" << endl;
	SetWinnerScreenColor(RoundInfo.Winner);
}
enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerwinTimes)
{
	if (PlayerWinTimes > ComputerwinTimes)
		return enWinner::Player;
	else if (ComputerwinTimes > PlayerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}
stGameResults FillGameResults(int GameRounds, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;
	GameResults.GameRounds = GameRounds;
	GameResults.PlayerWinTimes = PlayerWinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(PlayerWinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);
	return GameResults;
}
enGameChoice ReadPlayerChoice()
{
	short Choice = 1;
	do {
		cout << "\mYourChoice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
		cin >> Choice;
	} while (Choice < 1 || Choice>3);
	return (enGameChoice)Choice;
}
enGameChoice GetCompterChoice()
{
	return (enGameChoice)randomNumber(1, 3);
}
stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begin : \n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.Computerchoice = GetCompterChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
		if (RoundInfo.Winner == enWinner::Player)
			PlayerWinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;
		PrintRoundResults(RoundInfo);
	}
	return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}
string Tabs(short NumberOfTabs)
{
	string t = "";
	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;
}
void ShowGameOverScreen()
{
	cout << Tabs(2) << "___________________________________________________________\n\n";
	cout << Tabs(2) << "              +++ G a m e O v e r +++\n";
	cout << Tabs(2) << "____________________________________________________________\n\n";
}
void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "____________________[Game Results]_______________________\n\n";
	cout << Tabs(2) << "Game Rounds\t\t:" << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player Won Times\t:" << GameResults.PlayerWinTimes << endl;
	cout << Tabs(2) << "Computer WonTimes\t:" << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw Times\t\t:" << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner\t\t:" << GameResults.WinnerName << endl;
	cout << Tabs(2) << "__________________________________________________\n";
	SetWinnerScreenColor(GameResults.GameWinner);
}
short ReadHowManyRounds()
{
	short GameRounds = 1;
	do {
		cout << "How many rounds 1 to 10? \n";
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
	do {
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen;
		ShowFinalGameResults(GameResults);
		cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main()
{
	srand((unsigned)time(NULL));
	StartGame();
}
