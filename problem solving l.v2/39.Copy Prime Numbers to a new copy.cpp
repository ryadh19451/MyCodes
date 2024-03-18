#include <iostream>
using namespace std;
enum enPrimeNotPrime{Prime=1,NotPrime=2};
enPrimeNotPrime CheckPrime(int num)
{
	int M = round(num / 2);
	for (int i = 2;i <= M;i++)
	{
		if (num % i == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}
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
void CopyPrimeNumbers(int arr[100], int arr2[100], int arrLength,int& arr2Length)
{
	for (int i = 0;i < arrLength;i++)
		if (CheckPrime(arr[i])==enPrimeNotPrime::Prime)
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
	CopyPrimeNumbers(arr, arr2, arrLength,arr2Length);
	cout << "Before\n";
	PrintArray(arr, arrLength);
	cout << "After\n";
	PrintArray(arr2, arr2Length);
}