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

ll dp[355][355];

ll gcd(ll a,ll b){
    if (b == 0) return a;
    return gcd(b,a % b);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    dp[1][0] = 1;
    for (int i = 1;i <= n;++i){dp[1][i] = i;}


    for (int i = 2;i <= n;++i){
        dp[i][0] = 1;
        for (int j = 1;j <= n;++j){
            dp[i][j] = dp[i - 1][j];
            for (int k = 1;k <= n;++k){
                if (j >= k && dp[i - 1][j - k]){
                    dp[i][j] = max(dp[i][j],(k * dp[i - 1][j - k])/gcd(k,dp[i - 1][j - k]));
                }
            }
        }
    }
    cout << dp[n][n];
}
