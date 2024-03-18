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
void PrintPatternNum(int num)
{
	for (int i = num; i>=1 ; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << char(i+64);
		}
		cout << "\n";
	}
}
int main()
{
	PrintPatternNum(readpositivenum("enter a positive num "));
}