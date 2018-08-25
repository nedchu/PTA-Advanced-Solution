#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
int encode(int h, int m, int s) {
  return (h * 60 + m) * 60 + s;
}

int rt() {
  int h, m, s;
  scanf("%d:%d:%d", &h, &m, &s);
  return encode(h, m, s);
}

const int N = 1e4+5;

vector<pii> t;

int main() {
  int n, k, l, r;
  while (scanf("%d%d", &n, &k) == 2) {
    for (int i = 0; i < n; i++) {
      l = rt();
      scanf("%d", &r);
      if (l <= encode(17, 0, 0)) {
        t.push_back({l, r * 60});
      }
    }
    n = t.size();
    sort(t.begin(), t.end());

    double sum = 0.;
    priority_queue<int, vector<int>, greater<int>> q;
    int cur = encode(8, 0, 0);
    for (int i = 0; i < n; i++) {
      tie(l, r) = t[i];
      cur = max(cur, l);
      while (!q.empty() && q.top() < cur) q.pop();

      if (q.size() == k) {
        cur = max(cur, q.top());
        q.pop();
      }
      sum += cur - l;
      q.push(cur + r);
    }
    printf("%.1f\n", sum / 60 / max(n, 1));
  }
  return 0;
}
