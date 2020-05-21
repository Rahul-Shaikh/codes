#include <iostream>
#include <cstring>

#define MAX_CHARS 26

using namespace std;

bool isValid(int *count)
{
	for (int i = 0; i < MAX_CHARS; i++)
	{
		if (count[i] > 1) return false;
	}
	return true;
}

void longSubstrWithoutRep(string str, int n)
{
	int count[MAX_CHARS];

	memset(count, 0, sizeof(count));

	count[str[0]-'a']++;
	int cur_start = 0, cur_end = 0;
	int max_len = 1, max_start = 0;

	for (int i = 1; i < n; i++)
	{
		count[str[i]-'a']++;
		cur_end++;

		while (!isValid(count))
		{
			count[str[cur_start++] - 'a']--;
		}

		if (max_len < cur_end - cur_start + 1)
		{
			max_len = cur_end - cur_start + 1;
			max_start = cur_start;
		}
	}

	cout << str.substr(max_start, max_len) << endl;

}

int main(void)
{
	string str = "geeksforgeeks";

	longSubstrWithoutRep(str, str.length());
}