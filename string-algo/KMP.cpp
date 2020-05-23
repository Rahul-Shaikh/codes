#include <cstring>
#include <iostream>

using namespace std;

void computeLPS(char *pat, int M, int *lps)  // M length of the pattern
{
  int len = 0;

  lps[0] = 0;

  int i = 1;

  while (i < M) {
    if (pat[i] == pat[len]) {  // if matches both the begining pattern and the
                               // current window iterator is increased
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];  // if len is not zero check from beginning of the
                             // sub pattern which matches with the prev
                             // character of the current window
      } else {
        lps[i] = 0;  // if len is zero go new with the new window
        i++;
      }
    }
  }
}

void KMPSearch(char *txt, char *pat) {
  int M = strlen(pat);
  int N = strlen(txt);

  int lps[M];
  computeLPS(pat, M, lps);

  int i = 0;
  int j = 0;

  while (i < N) {
    if (pat[j] == txt[i]) {
      i++;
      j++;
    }

    if (j == M) {
      cout << "pattern found at " << i - j << endl;
      j = lps[j - 1];
    }
    // mismatch after j matches
    else if (i < N && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];  //  dont match lps[0...lps[j-1]] since they will match
                         //  anyway
      else
        i++;
    }
  }
}

int main(void) {
  char pat[] = "ABABCABAB";
  char txt[] = "ABABDABACDABABCABABABCABAB";

  KMPSearch(txt, pat);
  return 0;
}
