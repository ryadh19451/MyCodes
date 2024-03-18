#include <iostream>
#include <string>
using namespace std;
int RandomNumber(int From, int To)
{
    int randnum = rand() % (To - From + 1) + From;
    return randnum;
}
enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
    {
        return char(RandomNumber(97, 122));
        break;
    }
    case enCharType::CapitalLetter:
    {
        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {
        return char(RandomNumber(33, 47));
        break;
    }
    case enCharType::Digit:
    {
        return char(RandomNumber(48, 57));
        break;
    }
    }
}
int ReadPositiveNumber(string message)
{
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
string GenerateWord(enCharType CharType, short length)
{
    string word;
    for (int i = 1; i <= length; i++)
    {
        word = word + GetRandomCharacter(CharType);
    }
    return word;
}
string GenerateKey()
{
    string key = "";
    key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4) ;
    return key;
}
void GenerateKeys(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key[ " << i << " ] : " << GenerateKey() << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("Enter How many keys do you generte "));
}