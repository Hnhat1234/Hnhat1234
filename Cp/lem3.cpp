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

ll dp[1 << 17][21];

ll c[20][20];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int n; cin >> n;
    for (int i = 0;i < n;++i){
        for (int j = 0;j < n;++j){
            cin >> c[i][j];
        }
    }

    for (int i = 0;i < (1 << n);++i){
        for (int j = 0;j < n;++j){
            dp[i][j] = 1e9;
        }
    }

    for (int i = 0;i < n;++i){
        dp[(1 << i)][i] = 0;
    }
    for (int s = 1;s < (1 << n);++s){
    for (int i = 0;i < n;++i){
        if (getbit(s,i)){
        for (int j = 0;j < n;++j){
            if (!getbit(s,j) && i != j){
                dp[s + (1 << j)][j] = min(dp[s + (1 << j)][j],dp[s][i] + c[i][j]);
            }
        }
        }
    }
    }
    ll ans = 1e9;
    for (int i = 0;i < n;++i){
        ans = min(ans,dp[(1 << n) - 1][i]);
    }

    cout << ans;
}
