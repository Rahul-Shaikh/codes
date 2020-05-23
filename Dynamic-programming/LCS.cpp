#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int LCS(char *s1, char *s2) {
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

  int len = table[len1][len2];
  char *str = new char[len + 1];
  str[len--] = '\0';

  int i = len1, j = len2;
  while (i > 0 && j > 0) {
    if (table[i][j] == 1 + table[i - 1][j - 1]) {
      str[len--] = s1[i - 1];
      cout << s1[i - 1] << endl;
      i--;
      j--;
    } else
      i--;
  }

  for (int i = 0; i < table[len1][len2]; i++) cout << str[i];
  cout << endl;

  return table[len1][len2];
}

int main(void) {
  char X[] = "ABCDGH";
  char Y[] = "AEDFHR";
  cout << "Length of LCS is \n" << LCS(X, Y) << endl;

  return 0;
}
