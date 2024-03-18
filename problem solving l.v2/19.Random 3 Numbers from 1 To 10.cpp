#include <iostream>
#include <cstdlib>
using namespace std;
int RandomNum(int from,int to)
{
    int RandNum = rand() % (to - from + 1) + from;
    return RandNum;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << RandomNum(1, 10) << endl;
    cout << RandomNum(1, 10) << endl;
    cout << RandomNum(1, 10) << endl;
}