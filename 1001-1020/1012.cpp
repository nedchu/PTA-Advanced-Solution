#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 1e6+5;
const int M = 105;

char s[] = "ACME";

int a[N][4];
int sum[4][M];

int main() {
  memset(a, -1, sizeof a);
  int n, m, x;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    for (int j = 1; j < 4; j++) {
      scanf("%d", a[x] + j);
    }
    a[x][0] = accumulate(a[x]+1, a[x]+4, 0) / 3;
    for (int j = 0; j < 4; j++) {
      sum[j][a[x][j]]++;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < M; j++) {
      sum[i][j] += sum[i][j-1];
    }
  }

  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    if (a[x][0] == -1) {
      puts("N/A");
    } else {
      int p = 0;
      for (int i = 1; i < 4; i++) {
        if (sum[p][a[x][p]] < sum[i][a[x][i]]) p = i;
      }
      printf("%d %c\n", n - sum[p][a[x][p]] + 1, s[p]);
    }
  }
  return 0;
}
