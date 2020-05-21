#include <stdlib.h>
#include <stdio.h>
#define rep(i, s, n) for(int i = s; i < n; i++)

int lcm(int *arr, int n);
int gcd(int a, int b);

int main(void)
{
    int n;
    printf("Enter the number of values you will enter : ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int)*n);
    printf("Enter the numbers : ");
    rep(i, 0, n) scanf("%d", &arr[i]);
    printf("The lcm of the numbers is : %d\n", lcm(arr, n));
    return 0;
}

int lcm(int *arr, int n)
{
    int ans = arr[0];
    rep(i, 1, n)
    {
        ans = (ans*arr[i])/gcd(arr[i], ans);
    }
    return ans;
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}