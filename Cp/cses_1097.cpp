#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll pre[5005], x[5005];

ll dp[5005][5005];

ll f(int l,int r){
    if (dp[l][r]){return dp[l][r];}

    if (l == r){return x[l];}

    return dp[l][r] = max(x[l] + (pre[r] - pre[l]) - f(l + 1,r),x[r] + (pre[r - 1] - pre[l - 1]) - f(l,r - 1));


}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;

    for (int i = 1;i <= n;++i){
        cin >> x[i];
        pre[i] = pre[i - 1] + x[i];
    }

    cout << f(1,n);
}
