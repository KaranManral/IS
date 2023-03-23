#include <iostream>
#include <string.h>

using namespace std;

string getInput()
{
	string s;
	cout << "Enter the Message" << endl;
	getline(cin, s);
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

int main()
{
	string msg = getInput();
	int n;
	cout << "Enter the key size" << endl;
	cin >> n;
	cout << "Encrypted Text = " << encrypt(msg, n);
	return 1;
}
