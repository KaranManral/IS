#include <iostream>
#include <string.h>

using namespace std;

string getPT()
{
    string s;
    cout << "Enter the Message" << endl;
    getline(cin, s);
    return s;
}

string getKey(int l)
{
    string s;
    cout << "Enter the key" << endl;
    getline(cin, s);
    if (s.length() == l)
        return s;
    else if (s.length() < l)
    {
        int i = s.length();
        int k = 0;
        while (i < l)
        {
            s += s.at(k++);
            if (k == s.length())
                k = 0;
            i++;
        }
        return s;
    }
    else
    {
        string s1 = "";
        for (int i = 0; i < l; i++)
        {
            s1 += s.at(i);
        }
        return s1;
    }
}

string encrypt(string msg, string key)
{
    string ct = "";
    for (int i = 0; i < msg.length(); i++)
    {
        char a = (char)(((msg.at(i) - 97 + key.at(i) - 97) % 26) + 65);
        ct += a;
    }
    return ct;
}

string decrypt(string msg, string key)
{
    string pt = "";
    for (int i = 0; i < msg.length(); i++)
    {
        char a = (char)(((26 + (msg.at(i) - 65) - (key.at(i) - 97)) % 26) + 97);
        pt += a;
    }
    return pt;
}

int main()
{
    string msg = getPT();
    string key = getKey(msg.length());
    char ch;
    cout << "Enter 1 to encrypt message \nEnter 2 to decrypt message" << endl;
    cin >> ch;
    switch (ch)
    {
    case '1':
    {
        cout << "Message = " << msg << endl;
        cout << "Key = " << key << endl;
        cout << "Encrypted Text = " << encrypt(msg, key);
        break;
    }
    case '2':
    {
        cout << "Message = " << msg << endl;
        cout << "Key = " << key << endl;
        cout << "Decrypted Text = " << decrypt(msg, key);
        break;
    }
    default:
        cout << "Wrong choice entered" << endl;
        break;
    }
    return 1;
}
