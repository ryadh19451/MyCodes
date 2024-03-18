#include <iostream>
using namespace std;
enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };
int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
enPrimeNotPrime CheckPrime(int num)
{
	int m = round(num / 2);
	for (int i = 2; i <= m; i++)
	{
		if (num % i == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}
void PrintResult(int num)
{
	cout << "Prime numbers from 1 to " << num << " are" << endl;
	for (int i = 1; i <= num; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
			cout << i << endl;
	}
}
int main()
{
	PrintResult(ReadPositiveNumber(" Enter number "));
}