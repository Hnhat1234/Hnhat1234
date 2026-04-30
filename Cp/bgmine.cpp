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

const ll basehash = 31;
const ll modhash = 1000000003;

pair<ll,pair<ll,ll>> p[100005];

ll pre[100005], b[100005];

ll bit[100005];

void update(ll i,ll v){
    while (i > 0){
        bit[i] = min(bit[i],v);
        i -= (i & (-i));
    }
}
ll get(ll i,ll n){
    ll res = 1e18;

    while (i <= n){
        res = min(res,bit[i]);
        i += (i & (-i));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    for (int i = 1;i <= n;++i){
        ll x,g,r;
        cin >> x >> g >> r;
        p[i].first = x;
        p[i].second.first = g;
        p[i].second.second = r;
        bit[i] = 1e18;
    }
    sort(p + 1,p + 1 + n);
    ll cur = 0;
    for (int i = 1;i <= n;++i){
        pre[i] = pre[i - 1] + p[i].second.first;
        b[i] = p[i].first - cur;
        cur += p[i].second.second;
    }
    sort(b + 1,b + 1 + n);
    cur = 0;

    ll ans = 0;
    for (int i = 1;i <= n;++i){
        int value = lower_bound(b + 1,b + 1 + n,p[i].first - (cur + p[i].second.second)) - b;

        int v = lower_bound(b + 1,b + 1 + n,p[i].first - cur) - b;

        ans = max(ans,p[i].second.first);
        if (i == 1){update(v,pre[i - 1]); cur += p[i].second.second; continue;}
        ans = max(ans,pre[i] - get(value,n));
        update(v,pre[i - 1]);
        cur += p[i].second.second;
    }
    cout << ans;
}
