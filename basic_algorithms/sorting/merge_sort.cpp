#include <iostream>

using namespace std;
void merge_sort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);

int main(void)
{
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	merge_sort(arr, 0, n-1);

	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
}

void merge_sort(int	*arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end)/2;

		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);

		merge(arr, start, mid, end);
	}
}

void merge(int *arr, int start, int mid, int end)
{
	int nL = mid - start + 1, nR = end - mid;

	int L[nL], R[nR];

	for (int i = 0; i < nL; i++) L[i] = arr[start + i];
	for (int i = 0; i < nR; i++) R[i] = arr[mid + 1 + i];

	int i = 0, j = 0, k = start;
	while (i < nL && j < nR)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}

		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < nL)
	{
		arr[k] = L[i];
		i++, k++;
	}

	while (j < nR)
	{
		arr[k] = R[j];
		j++, k++;
	}
}