#include <iostream>
using namespace std;
void swap(int* n1, int* n2)
{
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
int main()
{
	int a = 1, b = 2;
	swap(&a, &b);
	cout << "a " << a << endl;
	cout << "b " << b << endl;
}