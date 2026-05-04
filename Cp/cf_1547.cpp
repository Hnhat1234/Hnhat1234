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

ll premin[300005], sufmax[300005];

ll a[300005];

pair<ll,ll> p[300005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int q; cin >> q;
    premin[0] = 1e18;
    while (q--){
        int n,k; cin >> n >> k;
        for (int i = 1;i <= k;++i){
            cin >> p[i].first;
        }
        for (int i = 1;i <= k;++i){
            cin >> p[i].second;
        }
        sort(p + 1,p + 1 + k);
        for (int i = 1;i <= k;++i){
            a[i] = p[i].first;
            premin[i] = min(premin[i - 1],p[i].second - p[i].first);
        }
        sufmax[k + 1] = 1e18;
        for (int i = k;i >= 1;--i){
            sufmax[i] = min(sufmax[i + 1],p[i].second + p[i].first);
        }
        for (int i = 1;i <= n;++i){
            int pos = lower_bound(a + 1,a + 1 + k,i) - a;
            ll res = 1e18;
            if (pos <= k){
                res = min(res,sufmax[pos] - i);
            }
            pos--;
            if (pos > 0){
                res = min(res,premin[pos] + i);
            }
            cout << res << ' ';
        }
        cout << '\n';
    }
}
