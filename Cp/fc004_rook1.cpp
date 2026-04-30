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

ll c[55][55];

ll p[55];
int main(){

    ll mod = 1000001;

    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    p[0] = 1;
    for (int i = 0;i <= 50;++i){c[0][i] = 1;}
    for (int i = 0;i <= 50;++i){c[i][i] = 1;}
    for (int i = 1;i <= 50;++i) p[i] = (p[i - 1] * i) % mod;

    for (int n = 1;n <= 50;++n){
        for (int k = 1;k < n;++k){
            c[k][n] = (c[k - 1][n - 1] + c[k][n - 1]) % mod;
        }
    }

    int t; cin >> t;
    while (t--){
        int n,m,k; cin >> n >> m >> k;
        cout << ((p[k] % mod) * ((c[k][n] * c[k][m]) % mod)) % mod << '\n';
    }
}
