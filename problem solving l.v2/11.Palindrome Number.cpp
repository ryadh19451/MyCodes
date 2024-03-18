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
int Reversenumber(int num)
{
	int Remainder = 0, num2 = 0;
	while (num > 0)
	{
		Remainder = num % 10;
		num = num / 10;
		num2 = num2 * 10 + Remainder;
	}
	return num2;
}
bool IsPalindromeNum(int num)
{
		return num == Reversenumber(num);
}
int main()
{
	if(IsPalindromeNum(readpositivenum("enter the main number ")))
	cout << "\n Yes, it is a Palindrome number \n";
	else
	cout << "\n No, it is NOT a Palindrome number \n";
}