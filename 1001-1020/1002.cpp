#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 1005;

double a[N];

int main() {
  int n, pos;
  double v;
  for (int _ = 0; _ < 2; _++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d%lf", &pos, &v);
      a[pos] += v;
    }
  }
  vector<int> p;
  for (int i = 0; i < N; i++) {
    if (a[i]) p.push_back(i);
  }
  printf("%d", p.size());
  if (!p.empty()) putchar(' ');
  reverse(all(p));
  for (int i = 0; i < p.size(); i++) {
    printf("%d %.1f%c", p[i], a[p[i]], i==p.size()-1 ? '\n' : ' ');
  }
  return 0;
}
