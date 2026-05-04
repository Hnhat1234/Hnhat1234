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

ll a[405], dp[405][405];

ll pre[405];


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    for (int i = 1;i <= n;++i){cin >> a[i]; pre[i] = pre[i - 1] + a[i];}

    memset(dp,1e18,sizeof(dp));

    for (int i = 1;i < n;++i){dp[i][i + 1] = a[i] + a[i + 1];}
    for (int i = 1;i <= n;++i){dp[i][i] = 0;}
    for (int i = n;i >= 1;--i){
        for (int j = i + 2;j <= n;++j){
            ll temp = 1e18;
            for (int k = i;k < j;++k){
                temp = min(temp,dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] = temp + pre[j] - pre[i - 1];
        }
    }
    cout << dp[1][n];
}
