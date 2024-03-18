#include <iostream>
#include <string>
using namespace std;
int RandomNumber(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;
	return randnum;
}
void fillArray(int arr[100],int& arrlength)
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
int MaxNumberInArray(int arr[100], int arrLength)
{
	int max = 0;
	for (int i = 0; i <= arrLength; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	fillArray(arr, arrLength);
	cout << "Array Elements ";
	PrintArray(arr, arrLength);
	cout << "Max number is ";
	cout << MaxNumberInArray(arr,arrLength);
}