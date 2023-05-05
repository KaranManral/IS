#include <bits/stdc++.h>

using namespace std;

int main()
{
    char r[7], v[7], e[7], h[3][7], h_trans[7][3], v_star[7];
    int s[3] = {0};
    string syndrome = "";

    map<string, string> table;
    table.insert({"100", "1000000"});
    table.insert({"010", "0100000"});
    table.insert({"001", "0010000"});
    table.insert({"110", "0001000"});
    table.insert({"011", "0000100"});
    table.insert({"111", "0000010"});
    table.insert({"101", "0000001"});

    cout << "Enter the transmitted codeword" << endl;
    for (int i = 0; i < 7; i++)
        cin >> v[i];
    cout << "Enter the received codeword" << endl;
    for (int i = 0; i < 7; i++)
        cin >> r[i];
    cout << "Enter the parity check matrix" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter row " << i << endl;
        for (int j = 0; j < 7; j++)
            cin >> h[i][j];
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 7; j++)
            h_trans[j][i] = h[i][j];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
            s[i] += (r[j] - 48) * (h_trans[j][i] - 48);
        s[i] %= 2;
        syndrome += (char)(s[i] + 48);
    }
    for (int i = 0; i < 7; i++)
        e[i] = (table[syndrome]).at(i);
    for (int i = 0; i < 7; i++)
        v_star[i] = (char)((((r[i] - 48) + (e[i] - 48)) % 2) + 48);
    cout << "\nTransmitted Message = ";
    for (int i = 0; i < 7; i++)
        cout << v[i];
    cout << "\nReceived Message = ";
    for (int i = 0; i < 7; i++)
        cout << r[i];
    cout << "\n\nDecoding Table" << endl
         << "Syndrome\tCoset Leaders" << endl;
    for (map<string, string>::iterator it = table.begin(); it != table.end(); ++it)
    {
        cout << it->first << "\t\t" << it->second << endl;
    }
    cout << "\nSyndrome = " << syndrome;
    cout << "\nAssumed error Pattern = ";
    for (int i = 0; i < 7; i++)
        cout << e[i];
    cout << "\nDecoded Received Message = ";
    for (int i = 0; i < 7; i++)
        cout << v_star[i];
    return 1;
}