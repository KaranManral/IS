#include <bits/stdc++.h>

using namespace std;

string generate_key(int n)
{
    string key = "";
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        key += (rand() % 2) + 48;
    return key;
}

string encrypt(string pt, string key)
{
    string ct = "";
    int n = pt.length();
    for (int i = 0; i < n; i++)
        ct += ((int(pt.at(i)) - 48) ^ (int(key.at(i)) - 48)) + 48;
    return ct;
}

int main()
{
    char choice;
    string key;
    do
    {
        int ch;
        cout << "\nEnter the choice\n1) Encrypt\n2) Decrypt" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter the message in Binary" << endl;
            string msg;
            getline(cin >> ws, msg);
            key = generate_key(msg.length());
            cout << "PT = " << msg << endl;
            cout << "Key= " << key << endl;
            cout << "Encrypted Text = " << encrypt(msg, key) << endl;
            break;
        }
        case 2:
        {
            cout << "Enter the message in Binary" << endl;
            string msg;
            getline(cin >> ws, msg);
            cout << "CT = " << msg << endl;
            cout << "Key= " << key << endl;
            cout << "Decrypted Text = " << encrypt(msg, key) << endl;
            break;
        }
        default:
            cout << "Wrong Choice Enterred" << endl;
            break;
        }
        cout << "Do you want to continue? (Y/N)" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 1;
}