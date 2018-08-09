#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head

void p(int x) {
  if (x < 1000) {
    printf("%d", x);
  } else {
    p(x / 1000);
    printf(",%03d", x % 1000);
  }
}

int main() {
  int a, b;
  while (scanf("%d%d", &a, &b) == 2) {
    a += b;
    if (a < 0) putchar('-'), a = - a;
    p(a);
    puts("");
  }
  return 0;
}
