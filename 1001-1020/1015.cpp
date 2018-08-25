#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
bool is_prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return x > 1;
}

int rev(int x, int d) {
  vector<int> v;
  while (x > 0) {
    v.push_back(x % d);
    x /= d;
  }
  int ans = 0;
  for (auto va: v) {
    ans *= d;
    ans += va;
  }
  return ans;
}

int main() {
  int n, d;
  while (scanf("%d%d", &n, &d) == 2) {
    puts(is_prime(n) && is_prime(rev(n, d)) ? "Yes" : "No");
  }
  return 0;
}
