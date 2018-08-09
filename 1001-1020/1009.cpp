#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
typedef pair<int, double> pid;

pid read() {
  int x; double y;
  scanf("%d%lf", &x, &y);
  return make_pair(x, y);
}

const int N = 2005;

double poly_prod[N];

int main() {
  int n1, n2;
  vector<pid> poly1, poly2;
  scanf("%d", &n1);
  for (int i = 0; i < n1; i++) {
    poly1.push_back(read());
  }
  scanf("%d", &n2);
  for (int i = 0; i < n2; i++) {
    poly2.push_back(read());
  }

  for (auto p1: poly1) {
    for (auto p2: poly2) {
      poly_prod[p1.fi + p2.fi] += p1.se * p2.se;
    }
  }

  vector<int> ids;
  for (int i = N-1; i >= 0; i--) {
    if (poly_prod[i]) ids.push_back(i);
  }
  printf("%d", ids.size());
  if (!ids.empty()) putchar(' ');
  for (int i = 0; i < ids.size(); i++) {
    printf("%d %.1f%c", ids[i], poly_prod[ids[i]], i==ids.size()-1 ? '\n' : ' ');
  }
  return 0;
}
