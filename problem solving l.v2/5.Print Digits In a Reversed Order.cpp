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
void PrintDigits(int num)
{
	int Remainder = 0;
	while (num > 0)
	{
		Remainder = num % 10;
		num = num / 10;
		cout << Remainder<<endl;
	}
}
int main()
{
	PrintDigits(readpositivenum("enter positive number "));
}