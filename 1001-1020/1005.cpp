#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 105;

char s[105];
char dig[15][15] = {
  "zero", "one", "two", "three",
  "four", "five", "six",
  "seven", "eight", "nine"
};

int main() {
  while (scanf("%s", s) == 1) {
    int n = strlen(s);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += s[i] - '0';
    }
    sprintf(s, "%d", sum);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
      printf("%s%c", dig[s[i]-'0'], i==n-1 ? '\n' : ' ');
    }
  }
  return 0;
}
