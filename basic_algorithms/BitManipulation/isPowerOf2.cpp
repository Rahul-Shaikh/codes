#include <iostream>

using namespace std;
#define ll long long

bool isPowerOf2(ll x)
{
	return (x && !(x & (x-1)));
}

int main(void)
{
	cout << isPowerOf2(18014398509481984) << endl;
}