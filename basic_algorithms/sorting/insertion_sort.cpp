#include <iostream>

using namespace std;

void output_array(int *arr, int N)
{
	for (int i = 0; i < N; i++) cout << arr[i] << " ";
	cout << endl;
}

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void insertion_sort(int *arr, int N)
{
	for (int i = 1; i < N; i++)
	{
		int hole = i;
		int temp = arr[hole];
		while (hole > 0 && temp < arr[hole-1])
		{
			arr[hole] = arr[hole-1];
			hole--;
		}
		arr[hole] = temp;
	}
}

int main(void)
{
	int N;
	cin >> N;

	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	insertion_sort(arr, N);
	output_array(arr, N);
}