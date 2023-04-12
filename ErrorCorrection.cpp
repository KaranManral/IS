
// WAP to implement CRC error detection
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

string checksum = "";
const string GX = "x^8+x^7+x^6+x^4+x^2+1";

char *getDiv(char *input, int size) // Getting Dividend after adding bits of Generator Polynomial
{
    int hp = GX.at(2) - 48;
    char *temp = new char[size + hp];
    for (int i = 0; i < size; i++)
        temp[i] = input[i];
    for (int i = size; i < (size + hp); i++)
        temp[i] = '0';
    temp[size + hp] = '\0';
    return temp;
}
char *getDivisor() // Extracting Divisor from generating polynomial
{
    int hp = GX.at(2) - 48;
    char *temp = new char[hp + 1];
    for (int i = 0; i < GX.length() - 2; i++)
    {
        if (GX.at(i) == '^')
        {
            int put = GX.at(i + 1) - 48;
            temp[(hp - put)] = '1';
        }
    }
    temp[hp] = '1';
    for (int i = 0; i < hp + 1; i++)
    {
        if (temp[i] != '1')
            temp[i] = '0';
    }
    temp[hp + 1] = '\0';
    return temp;
}
string getXOR(string temp, char *divisor) // XOR function
{
    string str = "";
    for (int i = 0; i < temp.length(); i++)
    {
        if (((int)(temp.at(i) - 48) ^ (int)(divisor[i] - 48)) == 1)
            str += '1';
        else
            str += '0';
    }
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) == '1')
        {
            str = str.substr(i);
            count++;
            break;
        }
    }
    if (count == 0)
        str = "";
    return str;
}
string sender(char *dividend, char *divisor) // Sender Function
{
    string quotient = "";
    int divisorlen = (strlen(divisor));
    int dividendlen = (strlen(dividend));
    string temp = "";
    int count = 0;
    while (count <= dividendlen)
    {
        if (temp.length() == divisorlen)
        {
            quotient += '1';
            temp = getXOR(temp, divisor);
        }
        else
        {
            temp += dividend[count++];
            quotient += '0';
        }
    }
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp.at(i) != '\0')
            checksum += temp.at(i);
    }
    while (checksum.length() < (divisorlen - 1))
        checksum = '0' + checksum;
    return quotient;
}
void receiver(string msg, char *divisor) // Receiver Function
{
    string quotient = "";
    int divisorlen = (strlen(divisor));
    int dividendlen = msg.length();
    string temp = "";
    int count = 0;
    string remainder = "";
    while (count < dividendlen)
    {
        if (temp.length() == divisorlen)
        {
            quotient += '1';
            temp = getXOR(temp, divisor);
        }
        else
        {
            temp += msg.at(count++);
            quotient += '0';
        }
    }
    if (temp == divisor)
        temp = "0";
    remainder = temp;
    while (remainder.length() < (divisorlen - 1))
        remainder = '0' + remainder;
    cout << "Checksum=" << remainder << endl;
    string check = "";
    for (int i = 0; i < remainder.length(); i++)
    {
        check += '0';
    }
    if (remainder == check)
        cout << "Message Received Correctly" << endl;
    else
        cout << "Message not Received Correctly" << endl;
}
string getdistortedMsg(char *input, string msg) // Adding Error to Message
{
    string distortedMsg = "";
    srand(time(0));
    int random = rand() % (msg.length());
    if (random < strlen(input))
    {
        for (int i = 0; i < random; i++)
            distortedMsg += msg.at(i);
        if (msg.at(random) == '0')
            distortedMsg += '1';
        else
            distortedMsg += '0';
        for (int i = random + 1; i < msg.length(); i++)
            distortedMsg += msg.at(i);
    }
    else
        distortedMsg = msg;
    cout << "Message Received in Noisy Channel=" << distortedMsg << endl;
    return distortedMsg;
}
int main()
{
    int n;
    char *input, *dividend, *divisor;
    cout << "Enter the length of data" << endl;
    cin >> n;
    input = new char[n];
    cout << "Enter data bits" << endl;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    input[n] = '\0';
    dividend = getDiv(input, n);
    divisor = getDivisor();
    string quotient = sender(dividend, divisor);
    string msg = input + checksum;
    cout << "\nNoiseless Channel\n"
         << endl;
    cout << "\nSender\n"
         << endl;
    cout << "Initial Message=" << input << endl;
    cout << "Checksum=" << checksum << endl;
    cout << "Message with checksum=" << msg << endl;
    cout << "\nReceiver\n"
         << endl;
    receiver(msg, divisor);
    cout << "\nNoisy Channel\n"
         << endl;
    cout << "Initial Message=" << input << endl;
    cout << "Initial Message with checksum=" << msg << endl;
    receiver(getdistortedMsg(input, msg), divisor);
    return 1;
}