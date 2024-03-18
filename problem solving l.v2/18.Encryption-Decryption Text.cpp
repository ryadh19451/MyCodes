#include <iostream>
#include <string>
using namespace std;
string readtext()
{
	string text;
	cout << "Enter text ";
	getline(cin ,text);
	return text;
}
string EncryptText(string text, short EncryptionKey)
{
	for (int i=0;i<=text.length();i++)
	{
		text[i] = char((int)text[i] + EncryptionKey);
	}
	return text;
}
string DecryptText(string text, short EncryptionKey)
{
	for (int i = 0; i <= text.length(); i++)
	{
		text[i] = char((int)text[i] - EncryptionKey);
	}
	return text;
}
int main()
{
	const short EncryptionKey = 2; //this is the key.
    string TextAfterEncryption, TextAfterDecryption; 
    string Text = readtext();     
    TextAfterEncryption = EncryptText(Text, EncryptionKey);     
    TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionKey);    
    cout << "\nText Before Encryption : ";     
    cout << Text << endl;     
    cout << "Text After Encryption  : "; 
    cout << TextAfterEncryption << endl;   
    cout << "Text After Decryption  : ";     
    cout << TextAfterDecryption << endl; 
    return 0; 
} 