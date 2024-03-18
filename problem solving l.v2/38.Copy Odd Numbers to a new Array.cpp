#include <iostream>
using namespace std;
int RandomNum(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
void FillArrayWithRandomNum(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements ";
	cin >> arrLength;
	for (int i = 0;i < arrLength;i++)
	{
		arr[i] = RandomNum(1, 100);
	}
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0;i < arrLength;i++)
	{
		cout << arr[i]<<" ";
	}
	cout << "\n";
}
void AddArrayElement(int num, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = num;
}
void CopyOddNumber(int arr[100], int arr2[100], int arrLength,int& arr2Length)
{
	for (int i = 0;i < arrLength;i++)
		if (arr[i] % 2 != 0)
		{
			AddArrayElement(arr[i], arr2, arr2Length);
		}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100],arrLength;
	FillArrayWithRandomNum(arr, arrLength);
	int arr2[100],arr2Length=0;
	CopyOddNumber(arr, arr2, arrLength,arr2Length);
	cout << "Before\n";
	PrintArray(arr, arrLength);
	cout << "After\n";
	PrintArray(arr2, arr2Length);
}