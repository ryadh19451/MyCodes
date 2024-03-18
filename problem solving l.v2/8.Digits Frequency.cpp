#include <iostream>
using namespace std;
int readpositivenum(string message)
{
	int num = 0;
	do
	{
		cout << message << endl;
		cin >> num;
	} while (num <= 0);
	return num;
}
int CountDigitFrequency(short DigitsToCheck ,int num)
{
	int Remainder = 0,FreqCount=0;
	while (num > 0)
	{
		Remainder = num % 10;
		num = num / 10;
		if (DigitsToCheck == Remainder)
		{
			FreqCount++;
		}
	}
	return FreqCount;
}
int main()
{
	int num = readpositivenum("enter the main number ");
	short DigitToCheck = readpositivenum("Enter he Digit to check ");
	cout <<"\nDigit " << DigitToCheck << "Frequency is " << CountDigitFrequency(DigitToCheck, num) << " Time(s)";
}