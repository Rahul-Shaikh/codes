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

void bubble_sort(int *arr, int N)
{
	int sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		for (int i = 0; i < N-1; i++)
		{
			if (arr[i] > arr[i+1])
			{
				swap(arr[i], arr[i+1]);
				sorted = 0;
			}
		}
	}
}

int main(void)
{
	int N;
	cin >> N;

	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	bubble_sort(arr, N);
	output_array(arr, N);
}