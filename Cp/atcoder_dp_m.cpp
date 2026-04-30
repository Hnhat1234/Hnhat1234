#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll mod = 1e9 + 7;

ll dp[100005], a[105];

ll t[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int n,k; cin >> n >> k;
    for (int i = 1;i <= n;++i) cin >> a[i];

    dp[0] = 1;
    for (int i = 1;i <= n;++i){
        for (int x = 1;x <= k;++x) dp[x] = (dp[x] + dp[x - 1]) % mod;
        for (int x = 0;x <= k;++x){
            if (x > a[i]){t[x] = (dp[x] - dp[x - a[i] - 1] + mod) % mod;}
            else{t[x] = dp[x];}
        }
        swap(dp,t);
    }
    cout << dp[k];
}
