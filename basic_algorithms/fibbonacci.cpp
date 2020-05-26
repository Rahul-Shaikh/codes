#include <cmath>
#include <iostream>

using namespace std;

void multiply(long long F[2][2], long long M[2][2]);

void power(long long F[2][2], int n);

long long fibConst(int n) {
  double phi = (1 + sqrt(5)) / 2;

  return (long long)((pow(phi, n) / sqrt(5)) + 0.5);
}

long long fib(int n) {
  long long F[2][2] = {{1, 1}, {1, 0}};

  if (n == 0) return 0;
  power(F, n - 1);

  return F[0][0];
}

void power(long long F[2][2], int n) {
  if (n == 0 || n == 1) return;

  power(F, n / 2);
  multiply(F, F);
  long long M[2][2] = {{1, 1}, {1, 0}};
  if (n % 2 != 0) multiply(F, M);
}

void multiply(long long F[2][2], long long M[2][2]) {
  long long x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
  long long y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
  long long z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
  long long w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

int main(void) {
  for (int n = 1; n < 93; n++) cout << fib(n) << " " << fibConst(n) << endl;
}
