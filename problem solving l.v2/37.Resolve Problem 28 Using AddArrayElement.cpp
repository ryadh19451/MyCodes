#include <iostream>
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
	for (int i = 0;i < arrLength;i++)
		cout << arr[i] << " ";
	cout << "\n";
}
void AddArrayElement(int num, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = num;
}
void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationlength)
{
	for (int i = 0;i < arrLength; i++)
	{
		AddArrayElement(arrSource[i], arrDestination, arrDestinationlength);
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0, arr2Length = 0;
	fillArray(arr, arrLength);
	int arr2[100];
	CopyArrayUsingAddArrayElement(arr, arr2, arrLength, arr2Length);
	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrLength);
	cout << "\nArray 2 elements after copy:\n";
	PrintArray(arr2, arr2Length);
}