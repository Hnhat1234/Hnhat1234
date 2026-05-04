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

ll b[100005], bit[100005];

ll dp[100005];

pair<pair<int,int>,ll> p[100005];

void update(int i,int n,ll v){
    while (i <= n + 1){
        bit[i] = max(bit[i],v);
        i += (i & (-i));
    }
}
ll get(int i){
    ll res = 0;
    while (i > 0){
        res = max(res,bit[i]);
        i -= (i & (-i));
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    ll x,y,n; cin >> x >> y >> n;

    pair<pair<int,int>,ll> p[100005];
    for (int i = 1;i <= n;++i){
        ll a,b,c;cin >> a >> b >> c;
        p[i].first.first = a;
        p[i].first.second = b;
        p[i].second = c;
    }
    p[n + 1].first.first = x; p[n + 1].first.second = y;
    sort(p + 1,p + 1 + n);

    for (int i = 1;i <= n + 1;++i){b[i] = p[i].first.second;}
    sort(b + 1,b + 1 + n);

    for (int i = 1;i <= n + 1;++i){

        int pos = lower_bound(b + 1,b + 2 + n,p[i].first.second) - b;
        if (i == 1){
            dp[i] = p[i].second;
            update(pos,n,dp[i]);
        }else{

            dp[i] = p[i].second + get(pos);
            update(pos,n,dp[i]);
        }
    }
    cout << dp[n + 1];
}
