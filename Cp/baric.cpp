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

int m[105];

ll f[105][105];

ll pre[105], suf[105], cost[105][105];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,e; cin >> n >> e;
    for (int i = 1;i <= n;++i){cin >> m[i];}
    for (int i = 1;i <= n;++i){
        for (int j = i;j <= n;++j){
            if (i == j){
                ll s1 = 0; ll s2 = 0;
                for (int k = i + 1;k <= n;++k){
                    s1 += 2 * abs(m[k] - m[i]);
                }
                for (int k = i - 1;k >= 1;--k){
                    s2 += 2 * abs(m[k] - m[i]);
                }
                pre[i] = s2;
                suf[i] = s1;
            }else{
                ll res = 0;
                for (int k = i + 1;k <= j - 1;++k){
                    res += (abs(2 * m[k] - (m[i] + m[j])));
                }
                cost[i][j] = res;
            }
        }
    }
    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= n;++j){
            f[i][j] = 1e9;
        }
    }
    for (int i = 1;i <= n;++i){
        f[i][1] = pre[i] + suf[i];
        for (int k = 2;k <= min(n,i);++k){
            for (int j = i - 1;j >= 1;--j){
                f[i][k] = min(f[i][k],f[j][k - 1] - suf[j] + suf[i] + cost[j][i]);
            }
        }
    }

    ll ans= 1e9; ll cur = 1e9;
    for (int i = 1;i <= n;++i){
        for (ll j = 1;j <= n;++j){
            if (f[i][j] <= e){
                if (ans > j){ans = j; cur = f[i][j];}
                else if (ans == j){
                    cur = min(cur,f[i][j]);
                }
            }
        }
    }
    cout << ans << ' ' << cur;
}
