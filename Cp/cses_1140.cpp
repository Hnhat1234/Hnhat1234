#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[400005];

ll bit[400005];

ll dp[400005];

void update(int u,ll v,int n){
    while (u <= n){
        bit[u] = max(bit[u],v);
        u += (u & (-u));
    }
}

ll get(int u){
    ll s = 0;
    while (u > 0){
        s = max(s,bit[u]);
        u -= (u & (-u));
    }
    return s;
}

int main(){
    int n; cin >> n;

    pair<pair<ll,ll>,ll> p[200005];

    for (int i = 1;i <= n;++i){
        cin >> p[i].first.first >> p[i].first.second;

        cin >> p[i].second;

        a[i] = p[i].first.first; a[n + i] = p[i].first.second;
    }

    sort(a + 1,a + 1 + 2*n);

    sort(p + 1,p + 1 + n);

    ll ans = 0;

    for (int i = 1;i <= n;++i){
        p[i].first.first = lower_bound(a + 1, a + 1 + 2 * n,p[i].first.first) - a;
        p[i].first.second = lower_bound(a + 1, a + 1 + 2 * n,p[i].first.second) - a;
    }

    for (int i = 1;i <= n;++i){
        if (i == 1){dp[i] = p[i].second; update(p[i].first.second + 1,dp[i],n);}
        else{
            dp[i] = p[i].second + get(p[i].first.first - 1);

            update(p[i].first.second + 1,dp[i],n);
        }

        ans = max(ans,dp[i]);
    }

    cout << ans;
}
