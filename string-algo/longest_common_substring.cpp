#include <iostream>
#include <cstring>

using namespace std;
#define MAX 1000

void LCS(int DP[][MAX], string s1, string s2)
{
	int n1, n2;
	int max_len = 0, max_start = 0;
	for (int i = 0; i < (n1 = s1.length()); i++)
	{
		for (int j = 0; j < (n2 = s2.length()); j++)
		{
			if (s1[i] == s2[j]) 
			{
				DP[i+1][j+1] = 1 + DP[i][j];
				if (max_len < DP[i+1][j+1])
				{
					max_len = DP[i+1][j+1];
					if (max_start != i-max_len+1) max_start = i-max_len+1;
				}
			}
			else DP[i+1][j+1] = 0;
		}
	}

	cout << s1.substr(max_start, max_len) << endl;
}

int main(void)
{
	string s1 = "abcaxxyb";
	string s2 = "xbcaxxyd";

	int DP[MAX][MAX];
	memset(DP, 0, sizeof(DP));
	LCS(DP, s1, s2);
}