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

const ll basehash = 31;
const ll modhash = 1000000003;

ll pre[100005], suf[100005];

ll f[100005], g[100005];

ll a[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;

    ll cur = 0;
    f[0] = 1e18;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        f[i] = min(f[i - 1],pre[i] - cur);
        cur = max(cur,pre[i]);
    }
    if (n == 1){cout << a[n]; return 0;}
    g[n + 1] = 1e18;
    cur = 0;
    for (int i = n;i >= 1;--i){
        suf[i] = suf[i + 1] + a[i];
        g[i] = min(g[i + 1],suf[i] - cur);
        cur = max(cur,suf[i]);
    }
    ll ans = pre[n];
    f[0] = 0;
    for (int i = 1;i <= n;++i){
        ans = max(ans,pre[n] - (f[i - 1] + g[i]) + (-f[i - 1] - g[i]));
    }
    cout << ans;
}
