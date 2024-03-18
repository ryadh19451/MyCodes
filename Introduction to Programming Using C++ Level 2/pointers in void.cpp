#include <iostream>
using namespace std;

int main()
{
	void* ptr;
	int x = 50;
	float f1 = 10.5;
	ptr = &f1;
	cout << *(static_cast<float*>(ptr)) << endl;
	ptr = &x;
	cout << *(static_cast<int*>(ptr)) << endl;
}