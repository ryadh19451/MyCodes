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
int SumDigits(int num)
{
	int Remainder = 0,sum=0;
	while (num > 0)
	{
		Remainder = num % 10;
		num = num / 10;
		sum += Remainder;
	}
	return sum;
}
int main()
{
	cout<<"Sum of Digits = "<<SumDigits(readpositivenum("enter positive number "));
}