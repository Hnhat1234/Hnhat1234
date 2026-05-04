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

ll a[2005];

ll f[2005][(1 << 10) + 5];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int n; cin >> n;
    for (int i = 1;i <= n;++i) cin >> a[i];
    sort(a + 1,a + 1 + n);
    for (int i = 1;i <= n;++i){
        for (int j = 0;j < (1 << 10);++j){
            f[i][j] = -1;
        }
    }

    f[1][0] = 0; f[1][1] = 1;

    for (int i = 2;i <= n;++i){
        for (int k = 0;k < (1 << 10);++k){
            if (f[i - 1][k] != -1){
                int d = a[i] - a[i - 1]; int x;
                if (d > 9){x = 0;}
                else{x = (k << d) & ((1 << 10) - 1);}
                f[i][x] = max(f[i][x],f[i - 1][k]);
                if ((x & ((1 << 1) + (1 << 8) + (1 << 9))) == 0){
                    x|=1;
                    f[i][x] = max(f[i][x],f[i - 1][k] + 1);
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0;i < (1 << 10);++i){ans = max(ans,f[n][i]);}
    cout << n - ans;
}
