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

string encrypt(string s, int k)
{
    string msg = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
            msg += " ";
        else
        {
            msg += (char)(((s.at(i) - 97 + k) % 26) + 65);
        }
    }
    return msg;
}

string decrypt(string s, int k)
{
    string msg = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
            msg += " ";
        else
        {
            msg += (char)(((26 + s.at(i) - k - 65) % 26) + 97);
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
        int k;
        string msg1 = "";
        for (int i = 0; i < msg.length(); i++)
        {
            msg1 += tolower(msg.at(i));
        }
        cout << "Enter displacement to be used for encryption" << endl;
        cin >> k;
        cout << "Encrypted Messsage is :- " << encrypt(msg1, k);
        break;
    }
    case 2:
    {
        int k;
        string msg1 = "";
        for (int i = 0; i < msg.length(); i++)
        {
            msg1 += toupper(msg.at(i));
        }
        cout << "Enter displacement used in encryption" << endl;
        cin >> k;
        cout << "Decrypted Messsage is :- " << decrypt(msg1, k);
        break;
    }
    default:
    {
        cout << "Wrong choice selected.";
    }
    }
    return 1;
}