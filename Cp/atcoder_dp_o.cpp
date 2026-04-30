#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[25][25];

ll dp[(1 << 21) + 5];

int main(){
    ll mod = 1e9 + 7;

    int n; cin >> n;

    for (int i = 0;i < n;++i){
        for (int j = 0;j < n;++j){
            cin >> a[i][j];
        }
    }

    dp[0] = 1;

    for (int i = 0;i < (1 << n);++i){
        int mask = __builtin_popcount(i);

        for (int j = 0;j < n;++j){
            if (i & (1 << j) || !a[mask][j]){continue;}

            dp[i | (1 << j)] += dp[i];
            dp[i | (1 << j)]%=mod;
        }
    }

    cout << dp[(1 << n) - 1];
}
