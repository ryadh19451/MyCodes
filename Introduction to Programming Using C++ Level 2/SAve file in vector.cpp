#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void SavevectorToFile(string FilName,vector <string> vFileVector)
{
	fstream Myfile;
	Myfile.open(FilName, ios::out);
	if (Myfile.is_open())
	{
		for (string &Line:vFileVector)
		{
			if (Line != "")
			{
				Myfile << Line << endl;
			}
		}
		Myfile.close();
	}
}
int main()
{
	vector <string> vFileContent{ "Ali", "Shadi"};
	SavevectorToFile("MyFile.txt", vFileContent);
}