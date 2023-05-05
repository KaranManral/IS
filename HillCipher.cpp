//    17 17  5
// K= 21 18 21
//     2  2 19
// msg = paymoremoney

#include <iostream>

using namespace std;

int K[3][3];

void getKey()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter element " << i << "," << j << endl;
            cin >> K[i][j];
        }
    }
}

int getDeterminantInverse(int a[3][3])
{
    int det = 0, detInv = 0;
    det += a[0][0] * ((a[1][1] * a[2][2]) - (a[1][2] * a[2][1])) - a[0][1] * ((a[1][0] * a[2][2]) - (a[1][2] * a[2][0])) + a[0][2] * ((a[1][0] * a[2][1]) - (a[1][1] * a[2][0]));
    det %= 26;
    if (det < 0)
        det += 26;
    for (int i = 1; i <= det; i++)
    {
        detInv = (i * det) % 26;
        if (detInv == 1)
            return i;
    }
    return -1;
}

void getAdjoin(int a[3][3], int b[3][3])
{
    b[0][0] = (a[1][1] * a[2][2]) - (a[1][2] * a[2][1]);
    b[1][0] = -((a[1][0] * a[2][2]) - (a[1][2] * a[2][0]));
    b[2][0] = (a[1][0] * a[2][1]) - (a[1][1] * a[2][0]);
    b[0][1] = -((a[0][1] * a[2][2]) - (a[0][2] * a[2][1]));
    b[1][1] = (a[0][0] * a[2][2]) - (a[0][2] * a[2][0]);
    b[2][1] = -((a[0][0] * a[2][1]) - (a[0][1] * a[2][0]));
    b[0][2] = (a[0][1] * a[1][2]) - (a[0][2] * a[1][1]);
    b[1][2] = -((a[0][0] * a[1][2]) - (a[0][2] * a[1][0]));
    b[2][2] = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
}

void getInv(int det, int a[3][3], int b[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b[i][j] = det * a[i][j];
            b[i][j] %= 26;
            if (b[i][j] < 0)
                b[i][j] += 26;
        }
    }
}

string encrypt(string msg)
{
    string ct = "";
    if (msg.length() % 3 != 0)
        for (int i = msg.length() % 3; i < 3; i++)
            msg += "x";
    for (int i = 0; i < msg.length(); i += 3)
    {
        int P[3] = {(msg.at(i) - 97) % 26, (msg.at(i + 1) - 97) % 26, (msg.at(i + 2) - 97) % 26};
        int CT[3];

        for (int c = 0; c < 3; c++)
        {
            CT[c] = ((P[0] * K[0][c]) + (P[1] * K[1][c]) + (P[2] * K[2][c])) % 26;
            if (CT[c] < 0)
                CT[c] += 26;
        }
        ct += (char)(CT[0] + 65);
        ct += (char)(CT[1] + 65);
        ct += (char)(CT[2] + 65);
    }
    return ct;
}

string decrypt(string msg)
{
    string pt = "";
    int adj[3][3];
    int inv[3][3];
    if (msg.length() % 3 != 0)
        for (int i = msg.length() % 3; i < 3; i++)
            msg += "X";

    int detInv = getDeterminantInverse(K);

    getAdjoin(K, adj);
    getInv(detInv, adj, inv);

    for (int i = 0; i < msg.length(); i += 3)
    {
        int C[3] = {(msg.at(i) - 65) % 26, (msg.at(i + 1) - 65) % 26, (msg.at(i + 2) - 65) % 26};

        int PT[3];

        for (int c = 0; c < 3; c++)
        {
            PT[c] = ((C[0] * inv[0][c]) + (C[1] * inv[1][c]) + (C[2] * inv[2][c])) % 26;
            if (PT[c] < 0)
                PT[c] += 26;
        }
        pt += (char)(PT[0] + 97);
        pt += (char)(PT[1] + 97);
        pt += (char)(PT[2] + 97);
    }
    return pt;
}

int main()
{
    string msg;
    char ch;
    cout << "Enter 1 to encrypt a message \nEnter 2 to decrypt a cipher text" << endl;
    cin >> ch;
    switch (ch)
    {
    case '1':
    {
        cout << "Enter the key for encryption" << endl;
        getKey();
        cout << "Enter the message to be encrypted" << endl;
        getline(cin >> ws, msg);
        string message = "";
        for (int i = 0; i < msg.length(); i++)
        {
            if ((msg.at(i) >= 97 && msg.at(i) <= 122) || (msg.at(i) >= 65 && msg.at(i) <= 90))
                message += tolower(msg.at(i));
            else if (msg.at(i) == 32)
                continue;
            else
            {
                cout << "Invalid Message" << endl;
                return 0;
            }
        }
        cout << "Cipher Text :- " << encrypt(message);
        break;
    }
    case '2':
    {
        cout << "Enter the key for decryption" << endl;
        getKey();
        cout << "Enter the Cipher text to be decrypted" << endl;
        getline(cin >> ws, msg);
        string message = "";
        for (int i = 0; i < msg.length(); i++)
        {
            if ((msg.at(i) >= 97 && msg.at(i) <= 122) || (msg.at(i) >= 65 && msg.at(i) <= 90))
                message += toupper(msg.at(i));
            else
            {
                cout << "Invalid Cipher Text" << endl;
                return 0;
            }
        }
        cout << "Plain Text :- " << decrypt(message);
        break;
    }
    default:
        cout << "Wrong choice entered" << endl;
        break;
    }
    return 1;
}
