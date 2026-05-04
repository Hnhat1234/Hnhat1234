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

ll dp[100005][18];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);


    ll modm = 998244353;
    string s; cin >> s;

    int n = s.size();

    s = ' ' + s;
    for (int i = 1;i <= n;++i){
        if (i == 1){
            if (s[i] != '?') dp[i][s[i] - 48] = 1;
            else{
                for (int j = 0;j <= 9;++j){
                    dp[i][j] = 1;
                }
            }
        }else{
            int l = 0; int r = 9;
            if (s[i] != '?'){l = r = s[i] - 48;}
            for (int j = l;j <= r;++j){
                for (int mod = 0;mod <= 16;++mod){
                    dp[i][(mod*10 + j)%17] += dp[i - 1][mod];
                    dp[i][mod] %= modm;
                }
            }
        }
    }

    cout << dp[n][5];
}
