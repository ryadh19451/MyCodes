#include <iostream>
#include <string>
using namespace std;
int RandomNumber(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;
	return randnum;
}
void fillArray(int arr[100], int& arrlength)
{
	cout << "Enter Number of Elements ";
	cin >> arrlength;
	for (int i = 0; i < arrlength; i++)
		arr[i] = RandomNumber(1, 100);
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
void CopyArray(int arr[100], int arr2[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr2[i] = arr[i];
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	fillArray(arr, arrLength);
	int arr2 [100];
	CopyArray(arr, arr2, arrLength);
	cout << "Array Elements ";
	PrintArray(arr, arrLength);
	cout << "Copy Elements ";
	PrintArray(arr2, arrLength);
}