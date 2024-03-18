#include <iostream>
using namespace std;
int ReadNumber()
{
	int num;
	cout << "Please Enter Number you want to search for? \n";
	cin >> num;
	return num;
}
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
bool IsNumberInArray(int num, int arr[100], int arrLength)
{
	return FindNumberPositionInArray(num, arr, arrLength) != -1;
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
	if (!IsNumberInArray(Num,arr,arrLength))
		cout << "no,The number is not found";
	else
	{
		cout << "Yes it found ";
	}
	return 0;
}