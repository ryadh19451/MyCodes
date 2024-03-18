#pragma warning(disable:4996)
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	time_t t = time(0);
	char* dt = ctime(&t);
	cout << "Local Date and time is: " << dt << endl;
	tm* gmtm = gmtime(&t);
	dt = asctime(gmtm);
	cout << "UTC date and time is: " << dt;
}