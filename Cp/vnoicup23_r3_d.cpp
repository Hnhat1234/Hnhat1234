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

ll t[300005], a[300005];

ll prefix[300005];

vector<int> p[300005];

map<ll,ll> cnt;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,k; cin >> n >> k;

    for (int i = 1;i <= n;++i){
        cin >> t[i];
        p[t[i]].push_back(i);
    }
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        prefix[i] = a[i] + prefix[i - 1];
    }
    if (k == 1){cout << 0; return 0;}
    for (int i = 1;i <= k;++i){
        p[i].push_back(0);
        p[i].push_back(n + 1);
    }
    ll ans = 0;
    for (int i = 1;i <= k;++i){
        sort(p[i].begin(),p[i].end());
        ll ma = 0;
        ll cur = 0;

        for (int j = 1;j < (sz(p[i]) - 1);++j){
            cur += a[p[i][j]];
            ll r = p[i][j + 1] - 1;
            ans = max(ans,ma + prefix[r] - k * cur);
            ma = max(ma,k * cur - prefix[p[i][j]]);
        }
        ans = max(ans,prefix[p[i][1] - 1]);
        ans = max(ans,prefix[n] - prefix[p[i][sz(p[i]) - 2]]);
    }
    cout << ans;
}
