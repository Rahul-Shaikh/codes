#include <iostream>
#include <cstring>
using namespace std;

void longestPalSubstr(char s[])
{
	int n = strlen(s);

	bool table[n][n];

	memset(table, 0, sizeof(table));

	int maxLength = 1;
	int start = 0;

	// 1 letter
	for (int i = 0; i < n; i++) table[i][i] = 1;

	// 2 letter
	for (int i = 0; i < n-1; i++)
	{
		if (s[i] == s[i+1])
		{
			table[i][i+1] = true;
			maxLength = 2;
			start = i;
		}
	}

	// 3 or more
	for (int len = 3; len <=n; len++)
	{
		for (int i = 0; i < n-len+1; i++)
		{
			int j = i+len-1;

			if (table[i+1][j-1] && s[i] == s[j])
			{
				table[i][j] = true;

				if (len > maxLength)
				{
					maxLength = len;
					start = i;
				}
			}
		}
	}

	for (int i  = start; i < start + maxLength; i++) cout << s[i];

	cout << endl;
}

int main(void)
{
	char s[] = "gekes";

	longestPalSubstr(s);

}