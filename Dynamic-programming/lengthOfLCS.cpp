#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int lengthOfLCS(char *s1, char *s2) {
  int len1 = strlen(s1);
  int len2 = strlen(s2);

  int table[len1 + 1][len2 + 1];

  memset(table, 0, sizeof(table));

  for (int i1 = 1; i1 <= len1; i1++) {
    for (int i2 = 1; i2 <= len2; i2++) {
      if (s1[i1 - 1] == s2[i2 - 1])
        table[i1][i2] = 1 + table[i1 - 1][i2 - 1];
      else
        table[i1][i2] = max(table[i1 - 1][i2], table[i1][i2 - 1]);
    }
  }

  for (int i = 0; i < len1 + 1; i++) {
    for (int j = 0; j < len2 + 1; j++) {
      cout << table[i][j] << " ";
    }
    cout << endl;
  }

  return table[len1][len2];
}

int main(void) {
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  cout << "Length of LCS is \n" << lengthOfLCS(X, Y) << endl;

  return 0;
}
