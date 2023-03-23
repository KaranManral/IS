#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string getInput()
{
    string msg;

    cout << "Enter the message" << endl;
    getline(cin, msg);
    return msg;
}

string encrypt(string s)
{
    string msg = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
            msg += " ";
        else
        {
            msg += (char)(((s.at(i) - 97 + 3) % 26) + 65);
        }
    }
    return msg;
}

string decrypt(string s)
{
    string msg = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
            msg += " ";
        else
        {
            msg += (char)(((26 + s.at(i) - 3 - 65) % 26) + 97);
        }
    }
    return msg;
}

int main()
{
    string msg = getInput();
    int choice;
    cout << "Enter the choice:" << endl
         << "1 Encrypt the message" << endl
         << "2 Decrypt the message" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        string msg1 = "";
        for (int i = 0; i < msg.length(); i++)
        {
            msg1 += tolower(msg.at(i));
        }
        cout << "Encrypted Messsage is :- " << encrypt(msg1);
        break;
    }
    case 2:
    {
        string msg1 = "";
        for (int i = 0; i < msg.length(); i++)
        {
            msg1 += toupper(msg.at(i));
        }
        cout << "Decrypted Messsage is :- " << decrypt(msg1);
        break;
    }
    default:
    {
        cout << "Wrong choice selected.";
    }
    }
    return 1;
}