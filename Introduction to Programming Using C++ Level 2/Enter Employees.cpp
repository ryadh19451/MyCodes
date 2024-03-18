#include <iostream>
#include <vector>
using namespace std;
struct stEmployee
{
	string FirstName;
	string LastName;
	float salary;
};
void ReadEmployee(vector <stEmployee> &vEmployee)
{
	char PlayAgain = 'Y';
	while (PlayAgain == 'y' || PlayAgain == 'Y')
	{
		stEmployee TempEmployee;
		cout << "Enter Employee Details \n";
		cout << "FirstName: ";
		cin >> TempEmployee.FirstName;
		cout << "Last Name: ";
		cin >> TempEmployee.LastName;
		cout << "Salary: ";
		cin >> TempEmployee.salary;
		vEmployee.push_back(TempEmployee);
		cout << "Do you want to addd more? Y\N ";
		cin >> PlayAgain;
	}
}
void PrintEmployee(vector <stEmployee>& vEmployee)
{
	cout << "Vector Employee:\n";
	for (stEmployee& Employee : vEmployee)
	{
		cout << "FirstName: " << Employee.FirstName << endl;
		cout << "LastName: " << Employee.LastName << endl;
		cout << "salary: " << Employee.salary << endl;
		cout << endl;
	}
	cout << endl;
}
int main()
{
	vector <stEmployee> vEmployees;
	ReadEmployee(vEmployees);
	PrintEmployee(vEmployees);
}