#include <iostream>
using namespace std;
int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
} 

void FillArrayWithRandomNumbers(int arr[100],int& arrLength)
{
	cout << "Enter number of elements " << endl;
	cin >> arrLength;
	for (int i = 0;i < arrLength;i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0;i < arrLength;i++)
		cout << arr[i]<<" ";
	cout << "\n";
}
short FindNumberPositionInArray(int num, int arr[100], int arrLength)
{
	for (int i = 0;i < arrLength; i++)
	{
		if (arr[i] == num)
			return i;
	}
	return -1;
}
int ReadNumber()
{
	int num;
	cout << "Please Enter Number you want to search for? \n";
	cin >> num;
	return num;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "Array 1 elements\n";
	PrintArray(arr, arrLength);
	int Num = ReadNumber();
	cout << "Number you are looking for is " << Num << endl;
	short NumberPosition = FindNumberPositionInArray(Num, arr, arrLength);
	if (NumberPosition == -1)
		cout << "The number is not found";
	else
	{
		cout << "The Number found at position ";
		cout << NumberPosition << endl;
		cout << "The NUmber found at its order ";
		cout << NumberPosition + 1 << endl;
	}
}