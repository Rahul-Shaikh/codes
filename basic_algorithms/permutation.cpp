#include <iostream>

using namespace std;

void permute(string str, int l, int r) {
  if (l == r) {
    cout << str << endl;
  }

  else {
    for (int i = l; i <= r; i++) {
      swap(str[l], str[i]);

      permute(str, l + 1, r);  // recursion called

      swap(str[l], str[i]);  // backtracking
    }
  }
}
int main(void) {
  string str = "ABCD";

  int len = str.length();
  permute(str, 0, len - 1);
  return 0;
}
