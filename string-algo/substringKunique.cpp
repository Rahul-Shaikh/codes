#include <iostream>
#include <cstring>
using namespace std;

#define MAX_CHARS 26

bool isValid(int *count, int k)
{
	int val = 0;
	for (int i = 0; i < MAX_CHARS; i++)
	{
		if (count[i]) val++;
	}
	return (k>=val);
}

void Kuniques(string str, int k)
{
	int n = str.length();
	int u = 0; // unique chars

	int count[MAX_CHARS];

	memset(count, 0, sizeof(count));

	// checking the total number of unique chars
	for (int i = 0; i < n; i++)
	{
		if (count[str[i]-'a'] == 0) u++;
	}

	if (u < k)
	{
		cout << "Not enough unique characters.\n";
		return;
	}

	memset(count, 0, sizeof(count));

	int max_len = 1, max_start = 0;
	int curr_start = 0, curr_end = 0;

	count[str[0] - 'a']++; // putting the first element
	for (int i = 1; i < n; i++)
	{
		count[str[i]-'a']++;
		curr_end++;

		while (!isValid(count, k))
		{
			count[str[curr_start] - 'a']--;
			curr_start++;
		}

		if (max_len < curr_end - curr_start + 1)
		{
			max_len = curr_end - curr_start + 1;
			max_start = curr_start;
		}

	}
	cout << str.substr(max_start, max_len) << endl;
}

int main(void)
{
	string s = "aabacbebebe";
	int k = 3;
	Kuniques(s, k);
}