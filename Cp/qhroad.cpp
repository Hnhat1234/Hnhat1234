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

vector<pair<int,int>> adj;

int par[100005], ans[100005], c[100005];

int p[100005];

int Find(int u){
    if (par[u] == u) return u;
    return par[u] = Find(par[u]);
}
bool join(int u, int v) {
    u = Find(u); v = Find(v);
    if (u == v) return false;
    par[v] = u;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m,q; cin >> n >> m >> q;
    for (int i = 1;i <= m;++i){
        int u,v; cin >> u >> v;
        adj.push_back({u,v});
    }

    ll res = n;
    for (int i = 1;i <= q;++i){cin >> p[i]; c[p[i]] = 1;}

    for (int i = 1;i <= n;++i){par[i] = i;}

    for (int i = 1;i <= m;++i){
        if (c[i]){continue;}
        if (join(adj[i - 1].first,adj[i - 1].second)){
            res -= 1;
        }
    }

    for (int i = q;i >= 1;--i){
        ans[i] = res;
        if (join(adj[p[i] - 1].first,adj[p[i] - 1].second)){
            res -= 1;
        }
    }

    for (int i = 1;i <= q;++i){cout << ans[i] << '\n';}
}
