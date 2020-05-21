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

void selection_sort(int *arr, int N)
{
	int min;
	int sorted = 1;
	for (int i = 0; i < N - 1; i++)
	{
		min = i;
		sorted = 1;
		for (int j = i+1; j < N; j++)
		{
			if (arr[j] < arr[min]) min = j;
			if (arr[j-1] > arr[j]) sorted = 0;
		}
		if (sorted) break;
		swap(arr[i], arr[min]);
	}
}

int main(void)
{
	int N;
	cin >> N;

	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	selection_sort(arr, N);
	output_array(arr, N);
}