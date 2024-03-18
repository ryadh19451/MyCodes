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
int main()
{
	 cout<<"Reversd is "<<Reversenumber(readpositivenum("enter positive number "));
}