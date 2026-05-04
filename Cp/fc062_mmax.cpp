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

int a[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int n; cin >> n;
    for (int i = 1;i <= n;++i) cin >> a[i];
    sort(a + 1,a + 1 + n);

    int ans = 0;
    ans = max(ans,a[1] * a[2] * a[3]);
    ans = max(ans,a[n] * a[n - 1] * a[n - 2]);
    ans = max(ans,a[1] * a[2]);
    ans = max(ans,a[n] * a[n - 1]);
    ans = max(ans,a[1] * a[2] * a[n]);
    ans = max(ans,a[1] * a[n] * a[n - 1]);

    cout << ans;
}
