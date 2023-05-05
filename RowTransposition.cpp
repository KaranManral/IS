// msg = the simplest possible transpositions

#include <bits/stdc++.h>

using namespace std;

map<int, int> keymap;

string getInput()
{
    string s, s1 = "";
    cout << "Enter the Message" << endl;
    getline(cin >> ws, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
            continue;
        else
            s1 += s.at(i);
    }
    return s1;
}

string encrypt(string msg, char **a, int r, string key, int n)
{

    string ct = "";

    int l = 0, temp = msg.length() % n;
    if (temp != 0)
        temp = n - temp;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < n; j++)
        {
            if (l < msg.length())
                a[i][j] = msg.at(l++);
            else
                a[i][j] = (char)(123 - temp--);
        }
    char enCipher[r][n];
    int k = 0;
    int index = 0;
    map<int, int>::iterator it = keymap.begin();
    while (it != keymap.end())
    {
        it->second = index++;
        ++it;
    }
    for (int k = 0; k < n; k++)
    {
        int j = keymap[key[k]];
        for (int i = 0; i < r; i++)
        {
            enCipher[i][k] = a[i][j];
        }
    }
    cout << endl
         << "Key= " << key << endl;
    for (int i = 0; i < r; i++)
    {
        cout << "   " << i << " ";
        for (int j = 0; j < n; j++)
        {
            cout << enCipher[i][j];
            ct += enCipher[i][j];
        }
        cout << endl;
    }
    return ct;
}

string decrypt(string ct, char **a, int r, string key, int n)
{
    int l = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = ct.at(l++);

    map<int, int>::iterator it = keymap.begin();

    char decCipher[r][n];
    for (int k = 0; k < n && it != keymap.end(); k++, ++it)
    {
        int j = it->second;
        for (int i = 0; i < r; i++)
        {
            decCipher[i][k] = a[i][j];
        }
    }

    string pt = "";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pt += decCipher[i][j];
        }
    }
    return pt;
}

int main()
{
    char choice;
    do
    {
        string key;
        int ch;
        cout << "\nEnter the choice\n1) Encrypt\n2) Decrypt" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            string msg = getInput();
            cout << "Enter the key" << endl;
            getline(cin >> ws, key);
            int n = key.length();
            int row = ((msg.length() % n) == 0) ? msg.length() / n : (msg.length() / n) + 1;
            char **a = new char *[row];
            for (int i = 0; i < row; i++)
                a[i] = new char[n];
            for (int i = 0; i < key.length(); i++)
            {
                keymap[key.at(i)] = i;
            }
            cout << "Encrypted Text = " << encrypt(msg, a, row, key, n) << endl;
            break;
        }
        case 2:
        {
            string msg = getInput();
            cout << "Enter the key" << endl;
            getline(cin >> ws, key);
            int n = key.length();
            int row = ((msg.length() % n) == 0) ? msg.length() / n : (msg.length() / n) + 1;
            char **a = new char *[row];
            for (int i = 0; i < row; i++)
                a[i] = new char[n];
            for (int i = 0; i < key.length(); i++)
            {
                keymap[key.at(i)] = i;
            }
            cout << "Decrypted Text = " << decrypt(msg, a, row, key, n) << endl;
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