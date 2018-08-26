#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
typedef pair<string, string> pss;

int main() {
  int n;
  string s, in, out;
  while (cin >> n) {
    vector<pss> a, b;
    for (int i = 0; i < n; i++) {
      cin >> s >> in >> out;
      a.push_back({in, s});
      b.push_back({out, s});
    }
    sort(all(a));
    sort(all(b));
    cout << a.front().se << " " << b.back().se << endl;
  }
  return 0;
}
