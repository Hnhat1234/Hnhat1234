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

ll dp[10005][105];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);
    string k; int d;
    cin >> k >> d;
    int n = k.size();
    for (int i = 1;i < n;++i){
        for (int digit = 0;digit <= 9;++digit){
            if (i == 1){dp[i][digit % d] += 1; continue;}
            for (int lod = 0;lod < d;++lod){
                dp[i][(lod + digit) % d] += dp[i - 1][lod];
                dp[i][(lod + digit) % d] %= mod;
            }
        }
    }

    ll ans = -1; int s = 0;
    for (int i = 0;i < n;++i){
        for (int j = 0;j < (k[i] - 48);++j){
            ans = (ans + dp[n - i - 1][(mod * d - (s + j)) % d]) % mod;
        }
        s = (s + (k[i] - 48)) % d;
    }
    if (s == 0){ans++;}
    cout << (ans - 1 + mod) % mod;
}
