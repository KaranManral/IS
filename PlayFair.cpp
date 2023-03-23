#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

char mat[5][5];
char used[200];
int r = 0, c = 0;

string getInput()
{
    string keyword;
    cout << "Enter Keyword" << endl;
    cin >> keyword;
    getchar();
    return keyword;
}

void createMatrix(string key)
{
    used['J'] = 1;
    for (int i = 0; i < key.length(); i++)
    {
        if (!used[toupper(key.at(i))])
        {

            mat[r][c++] = toupper(key.at(i));
            used[toupper(key.at(i))] = 1;
            if (c % 5 == 0)
            {
                c = 0;
                r++;
            }
        }
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (used[i] == 1)
            continue;
        else
        {

            mat[r][c++] = i;
            used[i] = 1;
            if (c % 5 == 0)
            {
                if (r == 4 && c == 5)
                    break;
                c = 0;
                r++;
            }
        }
    }
}

void displayMatrix()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

string getReqMsg(string msg)
{
    int j = 0;
    string reqmsg = "";
    for (int i = 0; i < msg.length(); i++)
    {
        try
        {
            j = i + 1;
            if (msg.at(i) == ' ')
            {
                i++;
                j++;
            }
            if (msg.at(j) == ' ')
            {
                j++;
            }
            if (toupper(msg.at(i)) == toupper(msg.at(j)))
            {
                reqmsg += toupper(msg.at(i));
                reqmsg += "X";
                for (; j < msg.length(); j++)
                    reqmsg += msg.at(j);
                break;
            }
            else
            {
                reqmsg += toupper(msg.at(i));
                reqmsg += toupper(msg.at(j));
            }
            i = j;
        }
        catch (const std::out_of_range &oor)
        {
            reqmsg += toupper(msg.at(i));
        }
    }
    return reqmsg;
}

bool reqMsgCompleted(string msg)
{
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg.at(i) >= 97 && msg.at(i) <= 122)
            return false;
    }
    return true;
}

void encrypt(string msg)
{
    string encryptedMsg1 = "";
    string encryptedMsg2 = "";
    string reqmsg = getReqMsg(msg);
    while (!reqMsgCompleted(reqmsg))
    {
        reqmsg = getReqMsg(reqmsg);
    }
    if (reqmsg.length() % 2 != 0)
        reqmsg += "X";
    int P, Q, R, S, f1, f2;
    char x, y;
    for (int i = 0; i < reqmsg.length(); i += 2)
    {
        x = reqmsg[i];
        y = reqmsg[i + 1];
        f1 = f2 = 0;
        if (x == 'J')
            x = 'I';
        if (y == 'J')
            y = 'I';
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (x == mat[j][k])
                {
                    P = j;
                    Q = k;
                    f1 = 1;
                }
                if (y == mat[j][k])
                {
                    R = j;
                    S = k;
                    f2 = 1;
                }
                if (f1 && f2)
                {
                    break;
                }
            }
            if (f1 && f2)
            {
                break;
            }
        }
        if (P == R)
        {
            if (Q == 4)
            {
                encryptedMsg1 += mat[P][0];
                if (mat[P][0] == 'I')
                    encryptedMsg2 += 'J';
                else
                    encryptedMsg2 += mat[P][0];
            }
            else
            {
                encryptedMsg1 += mat[P][Q + 1];
                if (mat[P][Q + 1] == 'I')
                    encryptedMsg2 += 'J';
                else
                    encryptedMsg2 += mat[P][Q + 1];
            }
            if (S == 4)
            {
                encryptedMsg1 += mat[R][0];
                if (mat[R][0] == 'I')
                    encryptedMsg2 += 'J';
                else
                    encryptedMsg2 += mat[R][0];
            }
            else
            {
                encryptedMsg1 += mat[R][S + 1];
                if (mat[R][S + 1] == 'I')
                    encryptedMsg2 += 'J';
                else
                    encryptedMsg2 += mat[R][S + 1];
            }
        }
        else if (Q == S)
        {
            if (P == 4)
            {
                encryptedMsg1 += mat[0][Q];
                if (mat[0][Q] == 'I')
                    encryptedMsg2 += 'J';
                else
                    encryptedMsg2 += mat[0][Q];
            }
            else
            {
                encryptedMsg1 += mat[P + 1][Q];
                if (mat[P + 1][Q] == 'I')
                    encryptedMsg2 += 'J';
                else
                    encryptedMsg2 += mat[P + 1][Q];
            }
            if (R == 4)
            {
                encryptedMsg1 += mat[0][S];
                if (mat[0][S] == 'I')
                    encryptedMsg2 += 'J';
                else
                    encryptedMsg2 += mat[0][S];
            }
            else
            {
                encryptedMsg1 += mat[R + 1][S];
                if (mat[R + 1][S] == 'I')
                    encryptedMsg2 += 'J';
                else
                    encryptedMsg2 += mat[R + 1][S];
            }
        }
        else
        {
            encryptedMsg1 += mat[P][S];
            encryptedMsg1 += mat[R][Q];
            if (mat[P][S] == 'I')
                encryptedMsg2 += 'J';
            else
                encryptedMsg2 += mat[P][S];
            if (mat[R][Q] == 'I')
                encryptedMsg2 += 'J';
            else
                encryptedMsg2 += mat[R][Q];
        }
    }
    cout << "Encrypted Message with I:- " << encryptedMsg1 << endl;
    cout << "Encrypted Message with J:- " << encryptedMsg2 << endl;
}

void decrypt(string reqmsg)
{
    string decryptedMsg1 = "";
    string decryptedMsg2 = "";

    int P, Q, R, S, f1, f2;
    char x, y;
    for (int i = 0; i < reqmsg.length(); i += 2)
    {
        x = reqmsg[i];
        y = reqmsg[i + 1];
        f1 = f2 = 0;
        if (x == 'J')
            x = 'I';
        if (y == 'J')
            y = 'I';
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (x == mat[j][k])
                {
                    P = j;
                    Q = k;
                    f1 = 1;
                }
                if (y == mat[j][k])
                {
                    R = j;
                    S = k;
                    f2 = 1;
                }
                if (f1 && f2)
                {
                    break;
                }
            }
            if (f1 && f2)
            {
                break;
            }
        }
        if (P == R)
        {
            if (Q == 0)
            {
                decryptedMsg1 += tolower(mat[P][4]);
                if (mat[P][4] == 'I')
                    decryptedMsg2 += 'j';
                else
                    decryptedMsg2 += tolower(mat[P][4]);
            }
            else
            {
                decryptedMsg1 += tolower(mat[P][Q - 1]);
                if (mat[P][Q - 1] == 'I')
                    decryptedMsg2 += 'j';
                else
                    decryptedMsg2 += tolower(mat[P][Q - 1]);
            }
            if (S == 0)
            {
                decryptedMsg1 += tolower(mat[R][4]);
                if (mat[R][4] == 'I')
                    decryptedMsg2 += 'j';
                else
                    decryptedMsg2 += tolower(mat[R][4]);
            }
            else
            {
                decryptedMsg1 += tolower(mat[R][S - 1]);
                if (mat[R][S - 1] == 'I')
                    decryptedMsg2 += 'j';
                else
                    decryptedMsg2 += tolower(mat[R][S - 1]);
            }
        }
        else if (Q == S)
        {
            if (P == 0)
            {
                decryptedMsg1 += tolower(mat[4][Q]);
                if (mat[4][Q] == 'I')
                    decryptedMsg2 += 'j';
                else
                    decryptedMsg2 += tolower(mat[4][Q]);
            }
            else
            {
                decryptedMsg1 += tolower(mat[P - 1][Q]);
                if (mat[P - 1][Q] == 'I')
                    decryptedMsg2 += 'j';
                else
                    decryptedMsg2 += tolower(mat[P - 1][Q]);
            }
            if (R == 0)
            {
                decryptedMsg1 += tolower(mat[4][S]);
                if (mat[4][S] == 'I')
                    decryptedMsg2 += 'j';
                else
                    decryptedMsg2 += tolower(mat[4][S]);
            }
            else
            {
                decryptedMsg1 += tolower(mat[R - 1][S]);
                if (mat[R - 1][S] == 'I')
                    decryptedMsg2 += 'j';
                else
                    decryptedMsg2 += tolower(mat[R - 1][S]);
            }
        }
        else
        {
            decryptedMsg1 += tolower(mat[P][S]);
            decryptedMsg1 += tolower(mat[R][Q]);
            if (mat[P][S] == 'I')
                decryptedMsg2 += 'j';
            else
                decryptedMsg2 += tolower(mat[P][S]);
            if (mat[R][Q] == 'I')
                decryptedMsg2 += 'j';
            else
                decryptedMsg2 += tolower(mat[R][Q]);
        }
    }
    cout << "Decrypted Message with I:- " << decryptedMsg1 << endl;
    cout << "Decrypted Message with J:- " << decryptedMsg2 << endl;
}

int main()
{
    createMatrix(getInput());
    displayMatrix();
    string msg;
    char ch;
    cout << "Enter 1 to encrypt a message \nEnter 2 to decrypt a cipher text" << endl;
    cin >> ch;
    switch (ch)
    {
    case '1':
    {
        cout << "Enter the message to be encrypted" << endl;
        getline(cin >> ws, msg);
        for (int i = 0; i < msg.length(); i++)
        {
            if (msg.at(i) >= 97 && msg.at(i) <= 122)
                continue;
            else if (msg.at(i) == 32)
                continue;
            else
            {
                cout << "Invalid Message" << endl;
                return 0;
            }
        }
        encrypt(msg);
        break;
    }
    case '2':
    {
        cout << "Enter the Cipher text to be decrypted" << endl;
        getline(cin >> ws, msg);
        for (int i = 0; i < msg.length(); i++)
        {
            if (msg.at(i) >= 65 && msg.at(i) <= 90)
                continue;
            else
            {
                cout << "Invalid Cipher Text" << endl;
                return 0;
            }
        }
        decrypt(msg);
        break;
    }
    default:
        cout << "Wrong choice entered" << endl;
        break;
    }
    return 1;
}