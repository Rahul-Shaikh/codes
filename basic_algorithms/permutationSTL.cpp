#include <algorithm>
#include <iostream>

using namespace std;

void permute(int *arr, int n, int i) {
  if (i == n) {
    for (int itr = 0; itr < n; itr++) cout << arr[itr] << " ";
    cout << endl;
    return;
  }
  for (int j = i; j < n; j++) {
    permute(arr, n, i + 1);

    rotate(arr + i, arr + i + 1, arr + n);
  }
}

int main(void) {
  int arr[] = {3, 2, 5, 5};

  permute(arr, 4, 0);
  sort(arr, arr + 4);

  do {
    for (int i : arr) cout << i << " ";
    cout << endl;
  } while (next_permutation(arr, arr + 4));

  string str = string("rahul");
  sort(str.begin(), str.end());

  do {
    cout << str << endl;
  } while (next_permutation(str.begin(), str.end()));

  return 0;
}
