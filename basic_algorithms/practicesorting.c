#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rep(i, n) for(int i = 0; i < n; i++)

void insertion_sort(int * arr, int n);
void bubble_sort(int *arr, int n);
void merge_sort(int *arr, int n);
void quick_sort(int *arr, int start, int end);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int start, int end)
{
    int p, p_index;
    p = arr[end];
    p_index = start;
    for (int i = start; i <= end - 1; i++)
    {
        if (arr[i] <= p) swap(&arr[i], &arr[p_index++]);
    }
    swap(&arr[p_index], &arr[end]);
    return p_index;
}

int partition_r(int *arr, int start, int end)
{
    srand(time(NULL));
    int random = start + rand()%(end-start);
    swap(&arr[random], &arr[end]);
    return partition(arr, start, end);
}

void merge(int *arr, int *L, int nL, int *R, int nR)
{
    int r, l, a;
    r = l = a = 0;
    while ((l < nL) && (r < nR))
    {
        if (L[l] > R[r]) arr[a++] = R[r++];
        else arr[a++] = L[l++];
    }
    while (l < nL) arr[a++] = L[l++];
    while (r < nR) arr[a++] = R[r++];
}

int main(void)
{
    int n;
    printf("Enter the number of elements you will enter : ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    printf("Enter the numbers : ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("\nThe entered array is : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    quick_sort(arr, 0, n -1);
    printf("\nThe sorted array is : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int hole, value;
        value = arr[hole = i];
        while ((hole > 0) && (arr[hole - 1] > value))
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
}

void bubble_sort(int *arr, int n)
{
    rep(i, n - 1)
    {
        rep(j, n-i-1)
        {
            if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
        }
    }
}

void merge_sort(int *arr, int n)
{
    if (n < 2) return;
    int nR, nL, mid;
    nL = mid = n/2;
    nR = n - mid;
    int *L = (int*)malloc(sizeof(int)*nL);
    int *R = (int*)malloc(sizeof(int)*nR);
    rep(i, nL) L[i] = arr[i];
    rep(i, nR) R[i] = arr[i + mid];
    merge_sort(L, nL);
    merge_sort(R, nR);
    merge(arr, L, nL, R, nR);
}

void quick_sort(int *arr, int start, int end)
{
    if (start >= end) return;
    int p_index = partition_r(arr, start, end);
    quick_sort(arr, start, p_index-1);
    quick_sort(arr, p_index+1, end);
}