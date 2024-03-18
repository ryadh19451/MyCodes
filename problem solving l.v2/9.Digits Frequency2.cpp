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
int CountDigitFrequency(short DigitsToCheck,int num)
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
void PrintAllDigitsFrequency(int num)
{
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		short DigitsFrequency = 0;
		DigitsFrequency = CountDigitFrequency(i, num);
			if (DigitsFrequency > 0)
			{
				cout << "Digit " << i << " Frequency is " << DigitsFrequency << " Time(s)"<<endl;
			}
		}
	}
int main()
{
	int num = readpositivenum("enter the main number ");
	PrintAllDigitsFrequency(num);
}