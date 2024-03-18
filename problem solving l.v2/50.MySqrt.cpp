#include <iostream>
using namespace std;
int MySqrt(int num)
{
	return pow(num, 0.5);
}
int ReadNum()
{
	float num;
	cout << "Enter number ";
	cin >> num;
	return num;
}
int main()
{
	int Num = ReadNum();
	cout << "My sqrt Result " << MySqrt(Num) << endl;
	cout << "C++ sqrt Result " << sqrt(Num);
}