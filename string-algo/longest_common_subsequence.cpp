#include <iostream>
#include <cstring>

using namespace std;

void LCS(int DP[][100], string s1, string s2);

int main(void)
{
	string s1 = "Geeksforgeeks";
	string s2 = "Geeksgks";

	int n1 = s1.length();
	int n2 = s2.length();
	int DP[100][100];
	memset(DP, 0, sizeof(DP));

	LCS(DP, s1, s2);
}

void LCS(int DP[][100], string s1, string s2)
{
	int n1, n2;
	for (int i = 0; i < (n1 = s1.length()); i++)
	{
		for (int j = 0; j < (n2=s2.length()); j++)
		{
			if (s1[i] == s2[j]) DP[i+1][j+1] = 1 + DP[i][j];
			else DP[i+1][j+1] = max(DP[i][j+1], DP[i+1][j]);
		}
	}
	cout << "Ok\n";
	int index = DP[n1][n2];
	char lcs[index + 1];
	lcs[index] = '\0';
	int i = n1;
	int j = n2;
	while (i > 0 && j > 0)
	{
		if (s1[i-1] == s2[j-1])
		{
			lcs[index-1] = s1[i-1];
			i--, j--, index--;
		}
		else if (DP[i][j-1] > DP[i-1][j]) j--;
		else i--;
	}

	cout << lcs << endl;
}