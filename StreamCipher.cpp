#include <bits/stdc++.h>

using namespace std;

string keyword = "";

string generate_key(int n)
{
    string key = "";

    for (int i = 0; i < n; i++)

        return key;
}

string encrypt()
{
    string msg = "", ct = "", key = "";
    char t;
    int n;
    srand(time(NULL));
    cout << "Enter the length of message" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the message in Binary" << endl;
        cin >> t;
        if (t == '0' || t == '1')
        {
            char ke = (rand() % 2) + 48;
            char c = ((int(t) - 48) ^ (int(ke) - 48)) + 48;
            msg += t;
            key += ke;
            ct += c;
            cout << "Message = " << t << endl;
            cout << "Key = " << ke << endl;
            cout << "Encrypted Message = " << c << endl;
        }
        else
        {
            cout << "Invalid Input" << endl;
            return key;
        }
    }
    cout << "\nFinal Message = " << msg << endl;
    cout << "Final Key = " << key << endl;
    cout << "Final Encrypted Message = " << ct << endl;
    return key;
}

void decrypt(string key)
{
    string ct = "", pt = "";
    char t;
    int n = key.length();
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the ciphertext in Binary" << endl;
        cin >> t;
        if (t == '0' || t == '1')
        {
            char ke = key[k];
            char p = ((int(t) - 48) ^ (int(ke) - 48)) + 48;
            ct += t;
            pt += p;
            cout << "CT = " << t << endl;
            cout << "Key = " << ke << endl;
            cout << "Decrypted Text = " << p << endl;
            k++;
        }
        else
        {
            cout << "Invalid Input" << endl;
            return;
        }
    }
    cout << "\nFinal Cipher Text = " << ct << endl;
    cout << "Final Key Used = " << key << endl;
    cout << "Final Decrypted Text = " << pt << endl;
}

int main()
{
    char choice;
    do
    {
        int ch;
        cout << "\nEnter the choice\n1) Encrypt\n2) Decrypt" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            keyword = encrypt();
            break;
        }
        case 2:
        {
            if (keyword == "")
            {
                cout << "Enter the Key" << endl;
                getline(cin >> ws, keyword);
            }
            decrypt(keyword);
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