#include <iostream>

using namespace std;

bool iBit(int n, int i)
{
	i = 1 << i;
	if (n & i) return true;
	else return false;
}

int main(void)
{
	int n, i;
	cin >> n >> i;
	i--;
	cout << iBit(n, i) << endl;
}