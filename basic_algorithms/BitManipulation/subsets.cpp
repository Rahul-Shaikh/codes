#include <iostream>

using namespace std;

void printSubset(char A[], int n)
{
	for (int i = 0; i < (1<<n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) printf("%c ", A[j]);
		}
		printf("\n");
	}
}
int main(void)
{
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	while (getchar() != '\n');
	char A[n];
	cout << "Enter " << n << " elements: ";
	for (int i = 0; i < n; i++) cin >> A[i];
	printSubset(A, n);
}