#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 1e5+5;

char s[N][25];
int in[N], out[N];

int read_time() {
  int h, m, s;
  scanf("%d:%d:%d", &h, &m, &s);
  return (h * 60 + m) * 60 + s;
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    pii in_min(1e9, -1), out_max(-1, -1);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
      in[i] = read_time();
      out[i] = read_time();
      in_min = min(in_min, {in[i], i});
      out_max = max(out_max, {out[i], i});
    }
    printf("%s %s\n", s[in_min.se], s[out_max.se]);
  }
  return 0;
}
