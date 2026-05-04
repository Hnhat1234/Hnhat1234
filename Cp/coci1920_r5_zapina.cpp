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

#define sz(a) ((int)(a).size())s
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

using namespace std;

ll mod = 1e9 + 7;

ll f[355][355][2], c[355][355];


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("Hnhatn.inp","r",stdin);

    int n; cin >> n;

    for (int i = 0;i <= n;++i){c[i][i] = c[0][i] = 1;}
    for (int i = 1;i <= n;++i){
        for (int k = 1;k < i;++k){
            c[k][i] = (c[k - 1][i - 1] % mod + c[k][i - 1] % mod) % mod;
        }
    }

    f[0][0][0] = 1;
    for (int i = 1;i <= n;++i){
        for (int j = 0;j <= n;++j){
            for (int k = 0;k <= j;++k){
                if (i != k){
                    f[i][j][0] += ((c[k][n - j + k] * f[i - 1][j - k][0] % mod) % mod); f[i][j][0] %= mod;
                }else{
                    f[i][j][1] += ((c[k][n - j + k] * f[i - 1][j - k][0]) % mod); f[i][j][1] %= mod;
                }
                f[i][j][1] += ((c[k][n - j + k] * f[i - 1][j - k][1]) % mod); f[i][j][1] %= mod;
            }
        }
    }
    cout << f[n][n][1];
}
