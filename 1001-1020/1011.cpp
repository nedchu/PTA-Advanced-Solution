#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
double a[3][3];
int choice[3];
char s[] = "WTL";

int main() {
  double prod = 1.;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%lf", a[i] + j);
    }
    choice[i] = max_element(a[i], a[i] + 3) - a[i];
    prod *= a[i][choice[i]];
  }

  for (int i = 0; i < 3; i++) {
    printf("%c ", s[choice[i]]);
  }
  printf("%.2f\n", (prod * .65 - 1) * 2 + 1e-8);
  return 0;
}
