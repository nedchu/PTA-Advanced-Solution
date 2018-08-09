#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 1e4+5;

int a[N];

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int l = 0, cur = 0;
    int ans = -1, ans_l, ans_r;
    for (int i = 0; i < n; i++) {
      if (cur >= 0) {
        cur += a[i];
      } else {
        cur = a[i], l = i;
      }
      if (cur > ans) {
        tie(ans, ans_l, ans_r) = make_tuple(cur, l, i);
      }
    }
    if (ans < 0) {
      tie(ans, ans_l, ans_r) = make_tuple(0, 0, n-1);
    }
    printf("%d %d %d\n", ans, a[ans_l], a[ans_r]);
  }
  return 0;
}
