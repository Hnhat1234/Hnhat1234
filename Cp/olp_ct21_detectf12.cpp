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

ll sqr(ll a){return a * a;}

ll pa[1005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    ll n,fo,d;
    cin >> n >> fo >> d;

    pair<ll,ll> p[1005];
    for (int i = 1;i <= n;++i){
        cin >> p[i].first >> p[i].second;
    }
    pa[fo] = 1;
    vector<int> b;
    for (int i = 1;i <= n;++i){
        if (i == fo) continue;
        if (sqr(p[i].first - p[fo].first) + sqr(p[i].second - p[fo].second) < d * d){pa[i] = 1; b.push_back(i);}

    }
    int f2 = 0;
    for (int i = 1;i <= n;++i){
        if (pa[i]) continue;
        for (int j = 0;j < b.size();++j){
            if (sqr(p[i].first - p[b[j]].first) + sqr(p[i].second - p[b[j]].second) < d * d){f2++; break;}
        }
    }
    cout << b.size() << ' ' << f2;
}
