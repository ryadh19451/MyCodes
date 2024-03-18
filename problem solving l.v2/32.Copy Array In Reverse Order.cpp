#include<iostream>
using namespace std;
int RandomNumber(int From, int To)
{ //Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum; 
} 
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{     
	cout << "\nEnter number of elements:\n";
	cin >> arrLength;
	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumber(1,100); 
} 
void PrintArray(int arr[100], int arrLength) 
{ 
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n"; 
} 
void CopyArrayInReverseOrder(int arr[100], int arr2[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr2[i] = arr[arrLength - 1 - i];
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100],arrLength,arr2[100];
	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrLength);
	CopyArrayInReverseOrder(arr, arr2, arrLength);
	cout << "\nArray2 elements after copy\n";
	PrintArray(arr2, arrLength);
	return 0;
}