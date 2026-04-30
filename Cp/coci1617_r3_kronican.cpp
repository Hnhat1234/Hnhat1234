#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define maxi(a, b) a = max(a, b)
#define mize(a, b) a = min(a, b)
#define getbit(a, i) ((a >> i)&1)

#define FOR(i, a, b) for(int i=a, _n=b; i<=_n; ++i)
#define FORD(i, a, b) for(int i=a, _n=b; i>=_n; --i)
#define REP(i, _n) for(int i=0; i<_n; ++i)

#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair

#define ii pair<int, int>

using namespace std;

int dp[1 << 22];

int c[25][25];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int n,k; cin >> n >> k;
    for (int i = 0;i < n;++i){
        for (int j = 0;j < n;++j){
            cin >> c[i][j];
        }
    }

    int ans = 1e9;
    for (int s = (1 << n) - 1;s > 0;--s){

        if (s != (1 << n) - 1) dp[s] = 1e9;
        if (__builtin_popcount(s) < k){continue;}

        for (int i = 0;i < n;++i){
            for (int j = 0;j < n;++j){
                if(getbit(s,i) && !getbit(s,j)){
                    dp[s] = min(dp[s],dp[s + (1 << j)] + c[j][i]);
                }
            }
        }

        if (__builtin_popcount(s) == k) ans = min(ans,dp[s]);
    }

    cout << ans;
}
