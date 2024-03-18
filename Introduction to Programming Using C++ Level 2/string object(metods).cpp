#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "My name is Ryad Hejazy, Ilove Programming.";
	//Print the Length of String
	cout << s1.length() << endl;
	//Print The letter at position 3
	cout << s1.at(3) << endl;
	//Add @programming Advices at the end of string
	s1.append(" @programming Advices");
	cout << s1 << endl;
	//insert Ali at position 7
	s1.insert(7," Ali ");
	cout << s1 << endl;
	//print all the next 8 letters from position 16
	cout << s1.substr(16, 8) << endl;
	//add one character to the end of the string
	s1.push_back('x');
	cout << s1 << endl;
	//remove one character from the end of the string
	s1.pop_back();
	cout << s1 << endl;
	//find Ali in the string
	cout<<s1.find("Ali") << endl;
	//find ali in the string
	cout << s1.find("ali") << endl;
	if (s1.find("ali") == s1.npos)
	{
		cout << "ali not found";
	}
	//clear all string
	s1.clear();
	cout << s1;
}