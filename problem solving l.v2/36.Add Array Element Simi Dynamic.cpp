#include <iostream>
using namespace std;
int ReadNumber()
{
	int num;
	cout << "Enter number? ";
	cin >> num;
	return num;
}
void AddArrayElement(int num, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = num;
}
void InputUserNumbersInArray(int arr[100], int& arrLength)
{
	bool AddMore = true;
	do {
		AddArrayElement(ReadNumber(), arr, arrLength);
		cout << "Do you want to add more number? [0]:No,[1]:Yes ";
		cin >> AddMore;
	} while (AddMore);
}
void PrintArray(int arr[100],int arrLength)
{
	for (int i = 0;i < arrLength;i++)
		cout << arr[i]<<" ";
	cout << "\n";
}
int main()
{
	int arr[100], arrLength = 0;
	InputUserNumbersInArray(arr, arrLength);
	cout << "Array Length " << arrLength << endl;
	cout << "array elements ";
	PrintArray(arr, arrLength);
}