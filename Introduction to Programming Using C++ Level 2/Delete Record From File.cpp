#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void LoadDataFromFiletoVector(string FileName,vector <string>& vFileVector)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			vFileVector.push_back(Line);
		}
		MyFile.close();
	}
}
void SaveVectorToFile(string FileName, vector <string>vFileContent)
{
	fstream MyFile;
	MyFile.open("MyFile.txt", ios::out);
	if (MyFile.is_open())
	{
		for (string Line : vFileContent)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}

}
void DeleteRecordFromFile(string FileName, string Record)
{
	vector<string>vFileContent;
	LoadDataFromFiletoVector(FileName, vFileContent);
	for (string& Line : vFileContent)
	{
		if (Line == Record)
		{
			Line = "";
		}
	}
	SaveVectorToFile(FileName, vFileContent);
}
void PrintFileContent(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open());
	{
		string Line;
		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}
		MyFile.close();
	}
}
int main()
{
	cout << "File Content Before Delete.\n";
	PrintFileContent("MyFile.txt");
	DeleteRecordFromFile("MyFile.txt", "Ali");
	cout << "\nFile content After Delete.\n";
	PrintFileContent("MyFile.txt");
}