#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head

int main() {
  int n, x, l = 0, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (l < x) ans += 5 + abs(x - l) * 6;
    if (l > x) ans += 5 + abs(x - l) * 4;
    if (l == x) ans += 5;
    l = x;
  }
  printf("%d\n", ans);
  return 0;
}
