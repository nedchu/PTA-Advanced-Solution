#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 105;
const int M = N;

struct Graph {
  struct Edge {
    int to, nxt;
    Edge(int to, int nxt) : to(to), nxt(nxt) {}
    Edge() {}
  };

  int head[N], cnt[N], ec, dep;
  bool root[N];
  Edge e[M];

  void addEdge(int from, int to) {
    e[ec] = Edge(to, head[from]);
    head[from] = ec++;
  }
  void init(int n) {
    ec = dep = 0;
    for (int i = 0; i <= n; i++) head[i] = -1, cnt[i] = 0;
  }
  void dfs(int x, int d) {
    dep = max(dep, d + 1);
    for (int i = head[x]; ~i; i = e[i].nxt) {
      int to = e[i].to;
      dfs(to, d + 1);
    }
    if (head[x] == -1) cnt[d]++;
  }
  void solve(int root) {
    dfs(root, 0);
    for (int i = 0; i < dep; i++) {
      printf("%d%c", cnt[i], i==dep-1 ? '\n' : ' ');
    }
  }
} g;

int main() {
  int n, m, k, u, v;
  scanf("%d%d", &n, &m);
  g.init(N-1);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &v);
      g.addEdge(u, v);
    }
  }
  g.solve(1);
  return 0;
}
