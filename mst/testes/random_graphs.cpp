#include <stdio.h>
#include <string.h>
#include <random>
#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;

int MA[MAXV][MAXV];
int pesos[MAXV];

int main(void) {
  int n, m, na;
  memset(MA, 0, sizeof(MA));
  scanf("%d %d", &n, &m);
  printf("%d\n%d\n", n, m);


  //for (int i = 0; i < MAXV; i++) MA[i][i] = 1;

  for (int i = 0; i < MAXV; i++) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist6(1, 200);
    pesos[i] = dist6(rng);
  }

  for (int i = 1; i < n; i++) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist6(0, i - 1);
    int tmp = dist6(rng);
    printf("%d %d %d\n", i, tmp, pesos[i - 1]);
    MA[i][tmp] = MA[tmp][i] = 1;
  }

  for (na = n - 1; na < m; ) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist6(0, n - 1);
    int tmp1 = dist6(rng);
    int tmp2 = dist6(rng);
    if (!MA[tmp1][tmp2]) {
      MA[tmp1][tmp2] = MA[tmp2][tmp1] = 1;
      if (tmp1 != tmp2) printf("%d %d %d\n", tmp1, tmp2, pesos[na + 1]);
      na++;
    }
  }
  return 0;
}
