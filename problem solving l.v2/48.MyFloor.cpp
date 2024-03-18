#include <iostream>
using namespace std;
int MyFloor(float Num)
{
	if (Num>0)
	{
		return int(Num);
	}
	else
	{
		return int(Num)-1;
	}
}
float ReadNum()
{
	float num;
	cout << "Enter number ";
	cin >> num;
	return num;
}
int main()
{
	float Num = ReadNum();
	cout << "My Floor Result " << MyFloor(Num) << endl;
	cout << "C++ Floor Result " << floor(Num);
}