#include <iostream>
using namespace std;
int main()
{
	int arr[4] = { 1,2,3,4 };
	int* ptr;
	ptr = arr;
	cout << "Adresses are: \n";
	for (int i = 0; i < 4; i++)
	{
		cout << ptr + i << endl;
	}
	cout << "variables are: \n";
	for (int i = 0; i < 4; i++)
	{
		cout << *ptr +i << endl;
	}
}