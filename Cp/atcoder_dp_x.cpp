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

ll dp[1005][20005];

bool cmp(pair<pair<ll,ll>,ll> x, pair<pair<ll,ll>,ll> y){
    return ((x.first.first + x.first.second) < (y.first.first + y.first.second));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    vector<pair<pair<ll,ll>,ll>> a;
    int n; cin >> n;
    for (int i = 1;i <= n;++i){
        ll w,s,v; cin >> w >> s >> v;
        a.push_back({{w,s},v});
    }
    sort(a.begin(),a.end(),cmp);

    ll ans = 0;


   for (int i = 0;i < n;++i){
        if (i == 0){dp[i][a[i].first.first] = a[i].second; continue;}
        for (int j = 1;j <= a[i].first.first + a[i].first.second;++j){
            if (j >= a[i].first.first){
                if (j - a[i].first.first == 0 || dp[i - 1][j - a[i].first.first])
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - a[i].first.first] + a[i].second);
            }
        }
    }

    for (int i = 1;i <= 10000;++i){ans = max(ans,dp[n - 1][i]);}
    cout << ans;
}
