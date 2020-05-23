#include <cstdlib>
#include <iostream>

using namespace std;

int count(int s[], int m, int n) {
  int table[n + 1][m];  // how many ways m types of coin can make n cents

  for (int i = 0; i < m; i++)
    table[0][i] = 1;  // 0 can be made only one way by every coins

  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < m; j++) {
      int x = (i - s[j] >= 0) ? table[i - s[j]][j] : 0;
      int y = (j >= 1) ? table[i][j - 1] : 0;

      table[i][j] = x + y;
    }
  }

  return table[n][m - 1];
}

int count2(int s[], int m, int n) {
  int dp[n + 1];  // how many ways n cents can be made
  memset(dp, 0, sizeof(dp));

  dp[0] = 1;

  for (int i = 0; i < m; i++)  // chooses every coin
  {
    for (int j = s[i]; j <= n; j++)  // checks every possible value where it can
                                     // be added and adds it accumulatively
    {
      dp[j] += dp[j - s[i]];
    }
  }
  return dp[n];
}

int main(void) {
  int arr[] = {1, 2, 3};
  int m = sizeof(arr) / sizeof(arr[0]);
  int n = 4;
  cout << count2(arr, m, n) << endl;
  return 0;
}
