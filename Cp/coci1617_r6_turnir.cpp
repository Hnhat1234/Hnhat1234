#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define maxi(a, b) a = max(a, b)
#define mize(a, b) a = min(a, b)
#define getbit(a, i) ((a) >> (i) & 1)

#define FOR(i, a, b) for(int i=a, _n=b; i<=_n; ++i)
#define FORD(i, a, b) for(int i=a, _n=b; i>=_n; --i)
#define REP(i, _n) for(int i=0; i<_n; ++i)

#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair

#define ii pair<int, int>

using namespace std;

const int maxn = 21;
int n;

int a[1 << maxn];

int tinh(int x) {
  if (x == 0) return 0;
  for (int i = n - 1; i >= 0; --i) {
    if ((1 << i) < x) x -= (1 << i);
    else
        return n - i;
  }
  return n;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    vector<int> b;

    cin >> n;
    for (int i = 0;i < (1 << n);++i){
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    for (int i = 0;i < (1 << n);++i){
        cout << tinh(b.end() - upper_bound(b.begin(),b.end(),a[i])) << ' ';
    }
}
