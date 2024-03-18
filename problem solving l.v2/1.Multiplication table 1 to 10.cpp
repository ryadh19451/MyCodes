#include <iostream>
using namespace std;
void PrintHeader()
{
	cout << "\n\t\t\tMultiplication table From 1 to 10\n\t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << "\n\t----------------------------------------------------------------------------\t\n";
}
string ColumnSperator(int i)
{
	if (i < 10)
		return ("    |");
	else
		return ("   |");
}
void PrintTable()
{
	PrintHeader();
	for (int i = 1; i <= 10; i++)
	{
		cout<< i << ColumnSperator(i)<<"\t";
		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
}
int main()
{
	PrintTable();
}