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
    char t, ch;
    int k = 0;
    srand(time(NULL));
    do
    {
        cout << "Enter the message in Binary" << endl;
        cin >> t;
        if (t == '0' || t == '1')
        {
            msg += t;
            key += (rand() % 2) + 48;
            ct += ((int(msg[k]) - 48) ^ (int(key[k]) - 48)) + 48;
            cout << "Message = " << msg << endl;
            cout << "Key= " << key << endl;
            cout << "Encrypted Message = " << ct << endl;
            cout << "Do you want to enter more text?(y/n)" << endl;
            cin >> ch;
            k++;
        }
        else
        {
            cout << "Invalid Input" << endl;
            return key;
        }
    } while (ch == 'y' || ch == 'Y');
    return key;
}

void decrypt(string key)
{
    string msg = "", pt = "";
    char t, ch;
    int k = 0;
    srand(time(NULL));
    do
    {
        cout << "Enter the message in Binary" << endl;
        cin >> t;
        if (t == '0' || t == '1')
        {
            msg += t;
            pt += ((int(msg[k]) - 48) ^ (int(key[k]) - 48)) + 48;
            cout << "Message = " << msg << endl;
            cout << "Key= " << key << endl;
            cout << "Decrypted Message = " << pt << endl;
            cout << "Do you want to enter more text?(y/n)" << endl;
            cin >> ch;
            k++;
        }
        else
        {
            cout << "Invalid Input" << endl;
            exit(0);
        }
    } while ((ch == 'y' || ch == 'Y') && (k < key.length()));
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
                cin >> keyword;
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