#include <iostream>

using namespace std;

int noOf1(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n-1);
		count ++;
	}
	return count;
}

int main(void)
{
	int n;
	cin >> n;
	cout << noOf1(n) << endl;
}