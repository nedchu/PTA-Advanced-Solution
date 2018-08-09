#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const ll INF = 9e18+5;

ll build(string s, ll radix) {
  ll ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (ans >= INF / radix) return INF;
    ans *= radix;
    int v = isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10;
    ans += v;
  }
  return ans;
}
int main() {
  string a, b;
  int tag, radix;
  cin >> a >> b >> tag >> radix;
  if (tag == 2) swap(a, b);
  ll l = 2, r = INF, ans = -1;
  for (int i = 0; i < b.size(); i++) {
    int v = isdigit(b[i]) ? b[i] - '0' : b[i] - 'a' + 10;
    l = max(l, v + 1LL);
  }
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (build(b, mid) < build(a, radix)) {
      l = mid + 1;
    } else if (build(b, mid) > build(a, radix)) {
      r = mid - 1;
    } else {
      ans = mid, r = mid - 1;
    }
  }
  if (ans == -1) {
    puts("Impossible");
  } else {
    printf("%lld\n", ans);
  }
  return 0;
}
