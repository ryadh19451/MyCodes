#include <iostream>
using namespace std;
float MyABS(float Num)
{
	if (Num > 0)
		return Num;
	else
		return Num * -1;
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
	cout << "My ABS Result " << MyABS(Num) << endl;
	cout << "C++ ABS Result " << abs(Num);
}