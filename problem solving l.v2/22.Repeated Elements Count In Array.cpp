#include <iostream>
#include <string>
using namespace std;
int ReadPositiveNumber(string message)
{
	int num = 0;
	do {
		cout << message << endl;
		cin >> num;
	} while (num <= 0);
	return num;
}
void ReadArray(int arr[100],int& arrLength)
{
	cout << "Enter number of elements ";
	cin >> arrLength;
	cout << "Enter array elements " << endl;
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Element[" << i+1 << "] :";
		cin >> arr[i];
	}
	cout << endl;
}
void PrintArray(int arr[100],int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
int TimeRepeated(int num, int arr[100], int arrLength)
{
	int count = 0;
	for (int i = 0; i <= arrLength - 1; i++)
	{
		if (num == arr[i])
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int arr[100], arrLength, NumberToCheck;
	ReadArray(arr, arrLength);
	NumberToCheck = ReadPositiveNumber("Enter number you want to check ");
	cout << "Original Array ";
	PrintArray(arr, arrLength);
	cout << "Number " << NumberToCheck;
	cout << " is repeated ";
	cout << TimeRepeated(NumberToCheck, arr, arrLength) << " time(S) ";
}