#include <iostream>
using namespace std;
/*int readpositivenum(string message)
{
	int num = 0;
	do
	{
		cout << message << endl;
		cin >> num;
	} while (num <= 0);
	return num;
}*/
void PrintPatternNum()
{
	int num = 0;
	string word = "";
	for (int i = 65; i<=90 ; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);
				cout << word << endl;
				word = "";
			}
		}
	}
	cout << "\n------------------------------------------------\n";
}
int main()
{
	PrintPatternNum();
}