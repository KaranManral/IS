#include <iostream>
#include <string.h>

using namespace std;

string getInput()
{
	string s;
	cout << "Enter the Message" << endl;
	getline(cin >> ws, s);
	return s;
}

string encrypt(string msg, int n)
{
	string ct = "";

	char a[n][msg.length()];
	memset(a, '_', sizeof(a[0][0]) * n * msg.length());

	int k = -1;
	bool flag = true;
	for (int i = 0; i < msg.length(); i++)
	{
		if (flag)
		{
			a[++k][i] = msg.at(i);
			if (k == n - 1)
				flag = false;
		}
		else
		{
			a[--k][i] = msg.at(i);
			if (k == 0)
				flag = true;
		}
	}
	if (k != 0)
		if (k != n - 1)
		{
			int l = msg.length();
			char b[n][l + k];
			memset(b, '_', sizeof(b[0][0]) * n * (l + k));
			for (int i = 0; i < n; i++)
				for (int j = 0; j < l; j++)
					b[i][j] = a[i][j];
			while (k > 0 && k < n - 1)
			{
				if (flag)
					b[++k][l++] = 'E';
				else
					b[--k][l++] = 'E';
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < l; j++)
				{
					cout << b[i][j];
					if (b[i][j] != '_')
						ct += toupper(b[i][j]);
				}
				cout << endl;
			}
			return ct;
		}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < msg.length(); j++)
		{
			cout << a[i][j];
			if (a[i][j] != '_')
				ct += toupper(a[i][j]);
		}
		cout << endl;
	}
	return ct;
}

string decrypt(string msg, int n)
{
	string pt = "";

	char a[n][msg.length()];
	memset(a, '_', sizeof(a[0][0]) * n * msg.length());

	int k = -1;
	bool flag = true;
	for (int i = 0; i < msg.length(); i++)
	{
		if (flag)
		{
			a[++k][i] = 'X';
			if (k == n - 1)
				flag = false;
		}
		else
		{
			a[--k][i] = 'X';
			if (k == 0)
				flag = true;
		}
	}
	int l = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < msg.length(); j++)
		{
			if (a[i][j] == 'X')
				a[i][j] = msg.at(l++);
			cout << a[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < msg.length(); i++)
		for (int j = 0; j < n; j++)
			if (a[j][i] != '_')
				pt += tolower(a[j][i]);
	return pt;
}

int main()
{
	char choice;
	string msg;
	int n, ch;
	do
	{
		cout << "Enter the choice\n1) Encrypt\n2) Decrypt\n3) Exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			msg = getInput();
			cout << "Enter the key size" << endl;
			cin >> n;
			cout << "Encrypted Text = " << encrypt(msg, n) << endl;
			break;
		}
		case 2:
		{
			msg = getInput();
			cout << "Enter the key size" << endl;
			cin >> n;
			cout << "Decrypted Text = " << decrypt(msg, n) << endl;
			break;
		}
		case 3:
			exit(1);
		default:
			cout << "Wrong Choice" << endl;
		}
		cout << "Do you want to continue? (Y/N)" << endl;
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
	return 1;
}
