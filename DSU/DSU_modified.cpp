#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long 
#define dbg(var) cout<<#var<<"="<<var<<"\n"
#define nl cout<<"\n"
#define fr(i,n) for(ll i=0;i<n;i++)
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define fast ios::sync_with_stdio(false);cin.tie(0);
#define vi vector<ll>
#define vvi vector< vi >
#define pb push_back
#define fa(v) for(auto &i:v)
#define all(v) v.begin(),v.end()

void initialize(int *arr, int *size, int N)
{
	fr(i, N)
	{
		arr[i] = i;
		size[i] = 1;
	}
}

int getRoot(int *arr, int i)
{
	while (arr[i] != i)
	{
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}

void _union(int* arr, int *size, int a, int b)
{
	int roota = getRoot(arr, a);
	int rootb = getRoot(arr, b);

	if (size[roota] < size[rootb])
	{
		arr[roota] = arr[rootb];
		size[rootb] += arr[roota];
	}

	else
	{
		arr[rootb] = arr[roota];
		size[roota] += arr[rootb];
	}
}

bool find(int* arr, int a, int b)
{
	if (getRoot(arr, a) == getRoot(arr, b)) return true;
	else return false;
}

void print_array(int *arr, int n)
{
	fr(i, n) cout << arr[i] << " ";
	nl;
}

int main(void)
{

	fast
	// cout << "Enter the number of elements in the array: " << endl;
	// cin >> N;
	int N = 10;
	int arr[N];
	int size[N];
	initialize(arr, size, N);

	print_array(arr, N);
	_union(arr, size, 2, 4);
	_union(arr, size, 6, 4);

	print_array(arr, N);
	cout << find(arr, 2, 6) << endl;

}



/*
	SLIGHTLY LESS MODIFIED DSU IMPLEMENTATION

	void initialize(int *arr, int N)
{
	fr(i, N)
	{
		arr[i] = i;
	}
}

int getRoot(int *arr, int i)
{
	while (arr[i] != i)
	{
		i = arr[i];
	}
	return i;
}

void _union(int* arr, int a, int b)
{
	int roota = getRoot(arr, a);
	int rootb = getRoot(arr, b);

	arr[roota] = rootb;
}

bool find(int* arr, int a, int b)
{
	if (getRoot(arr, a) == getRoot(arr, b)) return true;
	else return false;
}


*/