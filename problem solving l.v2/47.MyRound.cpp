#include <iostream>
using namespace std;
float GetFractionpart(float Num)
{
	return Num - int(Num);
}
int MyRound(float Num)
{
	int IntPart;
	IntPart = int(Num);
	float fractionPart = GetFractionpart(Num);
	if (abs(fractionPart) >= .5)
	{
		if (Num > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
	{
		return IntPart;
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
	cout << "My Round Result " << MyRound(Num) << endl;
	cout << "C++ Round Result " << round(Num);
}