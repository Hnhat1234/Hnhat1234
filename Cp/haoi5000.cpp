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

int a[100005]; ll pre[100005];

ll f[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    int n,k; cin >> n >> k;

    for (int i = 1;i <= k;++i) cin >> a[i];
    sort(a + 1,a + 1 + k);
    for (int i = 1;i <= k;++i){pre[i] = pre[i - 1] + a[i];}
    ll ans = 1e18;
    for (int i = 1;i <= k;++i){
        ll pos = lower_bound(a + 1,a + 1 + i,a[i] - n/2) - a;
        f[i] += (i - pos + 1) * a[i] - (pre[i] - pre[pos - 1]);
        f[i] += (pos - 1) * (n - a[i]) + pre[pos - 1];

        pos = upper_bound(a + 1 + i,a + 1 + k,a[i] + n/2) - a;
        f[i] += (k - pos + 1) * (n + a[i]) - (pre[k] - pre[pos - 1]);
        f[i] += pre[pos - 1] - pre[i - 1] - (pos - i) * a[i];

        ans = min(ans,f[i]);
    }
    cout << ans << '\n';
    int l = 1e6 + 5; int r = 0;
    for (int i = 1;i <= k;++i){
        if (f[i] == ans){
            l = min(l,a[i]);
            r = max(r,a[i]);
        }
    }
    cout << (r - l + 1) << '\n';
    for (int i = l;i <= r;++i){cout << i << ' ';}

}
