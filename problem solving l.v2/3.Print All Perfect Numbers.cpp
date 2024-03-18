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
bool PerfectNotPerfect(int num)
{
	int sum = 0;
	for (int i = 1; i < num; i++)
	{
		if (num % i == 0)
			sum += i;
	}
	return num == sum;
}
void printResult(int num)
{
	if (PerfectNotPerfect(num))
		cout << num << " is perfect number";
	else
		cout << num << " is NOT perfect number";
	
}
int main()
{
	printResult(readpositivenum("enter positive number "));
}