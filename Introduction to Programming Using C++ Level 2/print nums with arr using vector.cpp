#include <iostream>
#include <vector>
using namespace std;
void ReadNumber(vector <int> &vNumbers)
{
	char ReadMore = 'Y';
	int Number;
	while (ReadMore == 'y' || ReadMore == 'Y')
	{
		cout << "Enter Number ";
		cin >> Number;
		vNumbers.push_back(Number);
		cout << "\nDo yo want to read more numbers? Y/N ? ";
		cin >> ReadMore;
	}
}
void PrintNumber(vector <int> &vNumbers)
{
	cout << "Numbers Vector: \n\n";
	for (int Number : vNumbers)
	{
		cout << Number << endl;
	}
	cout << endl;
}
int main()
{