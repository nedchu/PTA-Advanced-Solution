#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 505;
const int M = 2e6+5;

const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int a[N];

struct Graph {
	struct Edge {
		int to, nxt, v;
		Edge(int to, int nxt, int v) : to(to), nxt(nxt), v(v) {}
		Edge() {}
	};

	int head[N], cnt[N], mx[N], ec;
	ll dis[N];
	Edge e[M];

	void addEdge(int from, int to, int v) {
		e[ec] = Edge(to, head[from], v);
		head[from] = ec++;
	}
	void init(int n) {
		ec = 0;
		for (int i = 0; i <= n; i++) head[i] = -1;
	}
  ll Dijkstra(int S, int T) {
    memset(dis, INF, sizeof dis);
    memset(cnt, 0, sizeof cnt);
    memset(mx, 0, sizeof mx);
    dis[S] = 0;
    cnt[S] = 1;
    mx[S] = a[S];
    priority_queue<pair<ll, int> > q;
    q.push({0, S});
    while (!q.empty()) {
      ll d = -q.top().fi;
      int cur = q.top().se;
      q.pop();
      if (d > dis[cur]) continue;
      if (cur == T) return dis[T];
      for (int i = head[cur]; ~i; i = e[i].nxt) {
        int to = e[i].to;
        if (dis[cur] + e[i].v < dis[to]) {
          dis[to] = dis[cur] + e[i].v;
          q.push({-dis[to], to});
          cnt[to] += cnt[cur];
          mx[to] = max(mx[to], mx[cur] + a[to]);
        } else if (dis[cur] + e[i].v == dis[to]) {
          cnt[to] += cnt[cur];
          mx[to] = max(mx[to], mx[cur] + a[to]);
        }
      }
    }
    return -1;
  }
} g;

int main() {
  int n, m, c1, c2, u, v, c;
  while (scanf("%d%d%d%d", &n, &m, &c1, &c2) == 4) {
    g.init(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &u, &v, &c);
      g.addEdge(u, v, c); g.addEdge(v, u, c);
    }
    g.Dijkstra(c1, c2);
    printf("%d %d\n", g.cnt[c2], g.mx[c2]);
  }
  return 0;
}
