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

ll dp[(1 << 16) + 5];

ll f[(1 << 16) + 5];

ll a[20][20];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n;cin >> n;
    for (int i = 0;i < n;++i){
        for (int j = 0;j < n;++j){
            cin >> a[i][j];
        }
    }

    for (int i = 0;i < (1 << n);++i){
        for (int j = 0;j < n;++j){
            for (int k = j + 1;k < n;++k){
                if ((i & (1 << j)) && (i & (1 << k))) f[i] += a[j][k];
            }
        }
    }

    for (int i = 0;i < (1 << n);++i){
        int j = ((1 << n) - 1)^i;
        for (int k = j;k > 0;k = (k - 1) & j){
            dp[i ^ k] = max(dp[i ^ k],dp[i] + f[k]);
        }
    }
    cout << dp[(1 << n) - 1];
}
