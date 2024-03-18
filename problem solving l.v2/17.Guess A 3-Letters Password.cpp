#include <iostream>
using namespace std;
string readnum()
{
	string password;
	cout << "Enter a 3-Letter Password (all capital)?\n";
	cin >> password;
	return password;
}
bool guessPassword(string OriginalPassword)
{
	string word = "";
	int counter = 0;
	cout << "\n";
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);
				counter++;
				cout << "Trial [" << counter << " ] : ";
				cout << word<<endl;
				if (word == OriginalPassword)
				{
					cout << "\nPassword is " << word << "\n";
					cout << "Found after ";
					cout << counter << " Trial(s)\n";
					return true;
				}
				word = "";
			}
		}
	}
	return false;
}
int main()
{
	guessPassword(readnum());
}