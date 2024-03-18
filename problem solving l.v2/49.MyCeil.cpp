#include <iostream>
using namespace std;
float GetFractionPart(float num)
{
	return num - int(num);
}
int MyCeil(float num)
{
	if (abs(GetFractionPart(num))>0)
	{
		if (num > 0)
			return int(num) + 1;
		else
			return int(num);
	}
	else
	{
		return num;
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
	cout << "My Ceil Result " << MyCeil(Num) << endl;
	cout << "C++ Ceil Result " << ceil(Num);
}