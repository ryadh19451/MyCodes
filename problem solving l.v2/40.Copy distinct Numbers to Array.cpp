#include <iostream>
using namespace std;
void fillArray(int arr[100], int& arrLength)
{
	arrLength = 10;
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0;i < arrLength;i++)
		cout << arr[i] << " ";
	cout << "\n";
}
short FindNumberPositionInArray(int num, int arr[100], int arrLength)
{
	for (int i = 0;i < arrLength;i++)
	{
		if (arr[i] == num)
			return i;
	}
	return -1;
}
bool IsNumberInArray(int num,int arr[100], int arrLength)
{
	return FindNumberPositionInArray(num, arr, arrLength) != -1;
}
void AddArrayElement(int num, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = num;
}
void CopyDistinationnumberInArray(int arr[100], int arr2[100], int arrlength, int& arr2Length)
{
	for (int i = 0;i < arrlength;i++)
	{
		if (!IsNumberInArray(arr[i], arr2, arr2Length))
		{
			AddArrayElement(arr[i], arr2, arr2Length);
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0, arr2[100], arr2Length = 0;
	fillArray(arr, arrLength);
	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrLength);
	CopyDistinationnumberInArray(arr, arr2, arrLength, arr2Length);
	cout << "\nArray2 distinct elements\n";
	PrintArray(arr2, arr2Length);
}