#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 1e3+5;

struct DSU {
  int fa[N];

  int find(int x) {
    return (x == fa[x]) ? x : (fa[x] = find(fa[x]));
  }
  void init(int n) {
    for (int i = 0; i <= n; i++) fa[i] = i;
  }
  void joint(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) fa[v] = u;
  }
  bool same(int u, int v) {
    return find(u) == find(v);
  }
} dsu;

pii e[N*N];

int main() {
  int n, m, k, u, v, x;
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &u, &v);
      e[i] = {u, v};
    }
    for (int i = 0; i < k; i++) {
      scanf("%d", &x);

      dsu.init(n);
      int ans = n - 2;
      for (int j = 0; j < m; j++) {
        tie(u, v) = e[j];
        if (u == x || v == x) continue;
        if (!dsu.same(u, v)) {
          dsu.joint(u, v);
          ans--;
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
