#include <iostream>
using namespace std;
enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };
string GetOpTypeSymbol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Sub:
		return "-";
	case enOperationType::Mul:
		return "*";
	case enOperationType::Div:
		return "/";
	default:
		return "Mix";
	}
}
string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
	string arrQuestionLevelText[4] = { "Easy","Med","Hard","Mix" };
	return arrQuestionLevelText[QuestionLevel - 1];
}
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void SetScreenColor(bool Right)
{
	if (Right)
		system("color 2F");
	else
	{
		system("color 4F");
		cout << "\a";
	}
}
short ReadHowManyQuestions()
{
	short NumberOfQuestions;
	do {
		cout << "How Many Questions do you want to answer ? ";
		cin >> NumberOfQuestions;
	} while (NumberOfQuestions < 1 || NumberOfQuestions>100);;
	return NumberOfQuestions;
}
enQuestionLevel ReadQuestionLevel()
{
	short QuestionLevel = 0;
	do
	{
		cout << "Enter Quetions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> QuestionLevel;
	} while (QuestionLevel < 1 || QuestionLevel>4);
	return (enQuestionLevel)QuestionLevel;
}
enOperationType ReadOpType()
{
	short OpType;
	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> OpType;
	} while (OpType < 1 || OpType>5);
	return enOperationType(OpType);
}
struct stQuestion
{
	int Num1;
	int Num2;
	enOperationType OperationType;
	enQuestionLevel QuestionLevel;
	int CorrectAnswer;
	int PlayerAnswer;
	bool AnswerResult;
};
struct stQuiz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions;
	enQuestionLevel QuestionLevel;
	enOperationType OpType;
	short NumberOfWrongAnswers;
	short NumberOfRightAnswers;
	bool isPass;
};
int SimpleCalculator(int Num1, int Num2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Num1 + Num2;
	case enOperationType::Sub:
		return Num1 - Num2;
	case enOperationType::Mul:
		return Num1 * Num2;
	case enOperationType::Div:
		return Num1 / Num2;
	default:
		return Num1 + Num2;
	}
}
enOperationType GetRandomOperationType()
{
	int Op = RandomNumber(1, 4);
	return (enOperationType)Op;
}
stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OpType)
{
	stQuestion Question;
	if (QuestionLevel == enQuestionLevel::Mix)
	{
		QuestionLevel = enQuestionLevel(RandomNumber(1, 3));
	}
	if (OpType == enOperationType::MixOp)
	{
		OpType = GetRandomOperationType();
	}
	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		Question.Num1 = RandomNumber(1, 10);
		Question.Num2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	case enQuestionLevel::Med:
		Question.Num1 = RandomNumber(10, 50);
		Question.Num2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	case enQuestionLevel::Hard:
		Question.Num1 = RandomNumber(50, 100);
		Question.Num2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	}
	return Question;
}
void GenerateQuizQuetion(stQuiz& Quiz)
{
	for (short Question = 0; Question < Quiz.NumberOfQuestions; Question++)
	{
		Quiz.QuestionList[Question] = GenerateQuestion(Quiz.QuestionLevel, Quiz.OpType);
	}
}
int ReadQuestionanswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}
void PrintTheQuestion(stQuiz& Quiz, short QuestionNumber)
{
	cout << "\n";
	cout << "Question[" << QuestionNumber + 1 << "/" << Quiz.NumberOfQuestions << "]\n\n";
	cout << Quiz.QuestionList[QuestionNumber].Num1 << endl;
	cout << Quiz.QuestionList[QuestionNumber].Num2 << " ";
	cout << GetOpTypeSymbol(Quiz.QuestionList[QuestionNumber].OperationType);
	cout << "\n________" << endl;
}
void CorrectTheQuestionAnswer(stQuiz& Quiz, short QuestionNumber)
{
	if (Quiz.QuestionList[QuestionNumber].PlayerAnswer != Quiz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quiz.QuestionList[QuestionNumber].AnswerResult = false;
		Quiz.NumberOfWrongAnswers++;
		cout << "Wrong Answer :-(\n";
		cout << "The Right Answer is: ";
		cout << Quiz.QuestionList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quiz.QuestionList[QuestionNumber].AnswerResult = true;
		Quiz.NumberOfRightAnswers++;
		cout << "Right Answer :-)\n";
	}
	cout << endl;
	SetScreenColor(Quiz.QuestionList[QuestionNumber].AnswerResult);
}
void AskAndCorrectQuestionListAnswer(stQuiz& Quiz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		PrintTheQuestion(Quiz, QuestionNumber);
		Quiz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionanswer();
		CorrectTheQuestionAnswer(Quiz, QuestionNumber);
	}
	Quiz.isPass = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);
}
string GetFinalResults(bool Pass)
{
	if (Pass)
		return "PASS :-)";
	else
		return "FAIL :-(";
}
void PrintQuizResults(stQuiz Quiz)
{
	cout << "\n";
	cout << "_______________________________\n\n";
	cout << "Final Resultd is " << GetFinalResults(Quiz.isPass);
	cout << "Number of Questions " << Quiz.NumberOfQuestions << endl;
	cout << "Question Level        " << GetQuestionLevelText(Quiz.QuestionLevel) << endl;
	cout << "OpType                " << GetOpTypeSymbol(Quiz.OpType) << endl;
	cout << "Number of Right Answers: " << Quiz.NumberOfRightAnswers << endl;
	cout << "Number of Wrong Answers: " << Quiz.NumberOfWrongAnswers << endl;
	cout << "________________________________\n";
}
void PlayMathGame()
{
	stQuiz Quiz;
	Quiz.NumberOfQuestions = ReadHowManyQuestions();
	Quiz.QuestionLevel = ReadQuestionLevel();
	Quiz.OpType = ReadOpType();
	GenerateQuizQuetion(Quiz);
	AskAndCorrectQuestionListAnswer(Quiz);
	PrintQuizResults(Quiz);
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
		PlayMathGame();
		cout << endl << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}