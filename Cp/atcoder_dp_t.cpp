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

ll mod = 1e9 + 7;

ll dp[3005][3005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;

    dp[1][1] = 1;
    for (int i = 2;i <= n;++i){
        for (int j = 1;j <= i;++j){
            if (s[i - 1] == '<'){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = (dp[i - 1][i - 1] - dp[i - 1][j - 1] + mod) % mod;
            }
        }
        for (int j = 1;j <= i;++j){
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }

    cout << dp[n][n];
}
