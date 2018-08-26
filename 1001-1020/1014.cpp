#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
// head
const int N = 25;
const int K = 1e3 + 5;

int cur_time[N];
queue<int> q[N];
int ans[K], ti[K];
int n, m, k, qs, x;

int encode(int h, int m) {
  return h * 60 + m;
}

void in(int x) {
  pii mn(1e9, -1);
  for (int i = 0; i < n; i++) {
    if (q[i].size() == m) continue;
    mn = min(mn, {q[i].size(), i});
  }

  if (mn.se != -1) {
    q[mn.se].push(x);
  }
}
void out() {
  pii mn(1e9, -1);
  for (int i = 0; i < n; i++) {
    if (q[i].empty()) continue;
    mn = min(mn, {cur_time[i] + ti[q[i].front()], i});
  }

  if (mn.se != -1) {
    int no = q[mn.se].front();
    q[mn.se].pop();
    cur_time[mn.se] += ti[no];
    ans[no] = cur_time[mn.se];
  }
}

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &qs);
  fill(cur_time, cur_time + N, encode(8, 0));

  for (int i = 0; i < k; i++) {
    scanf("%d", ti + i);
  }
  for (int i = 0; i < min(n * m, k); i++) {
    in(i);
  }
  for (int i = min(n * m, k); i < k; i++) {
    out();
    in(i);
  }
  for (int i = 0; i < n * m; i++) {
    out();
  }

  while (qs--) {
    scanf("%d", &x);
    x--;
    if (ans[x] - ti[x] >= encode(17, 0)) {
      puts("Sorry");
    } else {
      int h = ans[x] / 60, m = ans[x] % 60;
      printf("%02d:%02d\n", h, m);
    }
  }
  return 0;
}
