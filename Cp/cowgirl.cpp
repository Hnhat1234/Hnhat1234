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

ll f[30][(1 << 5) + 5];

bool check(ll a,ll b,int m){
    vector<int> x;
    vector<int> y;
    while (a != 0){
        x.push_back(a % 2);
        a/=2;
    }
    while (b != 0){
        y.push_back(b % 2);
        b/=2;
    }
    while (x.size() < m){x.push_back(0);}
    while (y.size() < m){y.push_back(0);}

    for (int i = 1;i < m;++i){
        if ((x[i] + x[i - 1] + y[i] + y[i - 1]) % 4 == 0){return false;}
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t;cin >> t;
    while (t--){
        int n,m; cin >> n >> m;
        if (n < m){swap(n,m);}
        memset(f,0,sizeof f);
        for (int i = 0;i < n;++i){
            for (int j = 0;j < (1 << m);++j){
                if (i == 0){f[i][j] += 1; continue;}
                for (int mask = 0;mask < (1 << m);++mask){
                    if (check(mask,j,m)){
                        f[i][mask] += f[i - 1][j];
                    }
                }
            }
        }
        ll ans = 0;
        for (int i = 0;i < (1 << m);++i){ans += f[n - 1][i];}
        cout << ans << '\n';
    }

}
