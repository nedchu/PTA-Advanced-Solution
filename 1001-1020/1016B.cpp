#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second


typedef long long ll;
typedef pair<int,int> pii;
// head
typedef pair<string, string> pss;

const int N = 1e3+5;

struct Bill {
  string name, time, type;
};

Bill s[N];
int a[24];
map<string, vector<pss>> data;

int get_time(string &s) {
  int M, d, h, m;
  sscanf(s.c_str(), "%d:%d:%d:%d", &M, &d, &h, &m);
  return (d * 24 + h) * 60 + m;
}

int get_charge(string &s) {
  int M, d, h, m;
  sscanf(s.c_str(), "%d:%d:%d:%d", &M, &d, &h, &m);
  int ans = 0;
  for (int i = 0; i < 24; i++) {
    if (i < h) {
      ans += a[i] * (d + 1) * 60;
    } else if (i == h) {
      ans += a[i] * (d * 60 + m);
    } else if (i > h) {
      ans += a[i] * d * 60;
    }
  }
  return ans;
}

int main() {
  for (int i = 0; i < 24; i++) {
    scanf("%d", a + i);
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> s[i].name >> s[i].time >> s[i].type;
  }
  sort(s, s + n, [](Bill &a, Bill &b) {
    return make_pair(a.name, a.time) < make_pair(b.name, b.time);
  });
  for (int i = 0; i + 1 < n; i++) {
    if (s[i].name == s[i+1].name && s[i].type != s[i+1].type && s[i].type == "on-line") {
      data[s[i].name].push_back({s[i].time, s[i+1].time});
    }
  }

  string month = s[0].time.substr(0, 2);
  for (auto &MM: data) {
    string name = MM.fi;
    vector<pss> &time = MM.se;
    sort(all(time));
    printf("%s %s\n", name.c_str(), month.c_str());
    int sum = 0;
    for (pss &p: time) {
      int dur = get_time(p.se) - get_time(p.fi);
      int charge = get_charge(p.se) - get_charge(p.fi);
      cout << p.fi.substr(3, 8) << " " << p.se.substr(3, 8) << " ";
      printf("%d $%d.%02d\n", dur, charge / 100, charge % 100);
      sum += charge;
    }
    printf("Total amount: $%d.%02d\n", sum / 100, sum % 100);
  }
  return 0;
}
