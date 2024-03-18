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
		arr[i] = RandomNum(-100, 100);
	}
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0;i < arrLength;i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
int NegativeCount(int arr[100], int arrLength)
{
	int counter = 0;
	for (int i = 0;i < arrLength;i++)
		if (arr[i] <= 0)
		{
			counter += 1;
		}
	return counter;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	FillArrayWithRandomNum(arr, arrLength);
	PrintArray(arr, arrLength);
	cout << "Number of NEGATIVE Arrays is : " << NegativeCount(arr,arrLength);
}