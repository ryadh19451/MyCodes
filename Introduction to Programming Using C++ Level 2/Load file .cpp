#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void LoadDataFromFiletoVector(string FilName,vector <string>& vFileVector)
{
	fstream Myfile;
	Myfile.open(FilName, ios::in);
	if (Myfile.is_open())
	{
		string Line;
		while (getline(Myfile, Line))
		{
			vFileVector.push_back(Line);
		}
		Myfile.close();
	}
}
int main()
{
	vector <string> vFileContent;
	LoadDataFromFiletoVector("MyFile.txt", vFileContent);
	for (string& line : vFileContent)
	{
		cout << line << endl;
	}
}