#include <iostream>

using namespace std;
#define fr(i, n) for (int i = 0; i < n; i++)

void print_array(int arr[], int n)
{
	fr(i, n) cout << arr[i] << " ";
	cout << endl;
}

void initialize(int arr[], int n)
{
	fr(i, n) arr[i] = i;
}

bool find(int arr[], int A, int B)
{
	return arr[A] == arr[B];
}

void _union(int arr[], int n, int A, int B)
{
	int temp = arr[A];
	fr(i, n)
	{
		if (arr[i] == temp) arr[i] = arr[B];
	}
}

int main(void)
{
	int N;

	ios::sync_with_stdio(false);cin.tie(0);
	cout << "Enter the number of elements in the array: " << endl;
	//cin >> N;
	N = 10;
	int arr[N];
	initialize(arr, N);

	print_array(arr, N);
	_union(arr, N, 2, 4);
	_union(arr, N, 6, 4);

	print_array(arr, N);
	cout << find(arr, 2, 6) << endl;

}