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

ll val[100005], bit[100005], n;

ll f[100005];

void update(int i,ll v){
    while (i <= n){
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
bool cmp(pair<ll,int> a,pair<ll,int> b){
    return (to_string(a.first) < to_string(b.first));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    ll a,b; cin >> a >> b;
    n = (b - a + 1);

    pair<ll,int> p[100005];
    for (ll i = a;i <= b;++i){
        p[i - a + 1] = mp(i,(i - a + 1));
    }
    sort(p + 1,p + 1 + n,cmp);
    for (int i = 1;i <= n;++i){
        val[p[i].second] = i;
    }


    for (int i = 1;i <= n;++i){
        f[i] = get(val[i] - 1) + 1;
        update(val[i],f[i]);
    }
    cout << n - *max_element(f + 1,f + 1 + n);
}
