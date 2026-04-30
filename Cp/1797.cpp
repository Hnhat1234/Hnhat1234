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

set<tuple<ll,ll>> q[100005];

vector<vector<int>> adj(100005);

ll a[100005], f[100005], sz[100005];

int pa[100005], son[100005];

void dfs(int u,int p){
    sz[u] = 1;
    f[u] = a[u];
    pa[u] = p;
    for (auto v:adj[u]){
        if (v == p) continue;
        dfs(v,u);
        sz[u] += sz[v];
        f[u] += f[v];
        q[u].insert(make_tuple(-sz[v],v));
        if(sz[v] > sz[son[u]] || sz[v] == sz[son[u]] && v < son[u]) son[u] = v;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m; cin >> n >> m;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for (int i = 1;i < n;++i){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    while (m--){
        int t,u; cin >> t >> u;
        if (t == 1){cout << f[u] << '\n';}
        else{
            ll v = son[u];
			if(!v) continue;
			ll p = pa[u];
			sz[u] -= sz[v];
			f[u] -= f[v];
			q[u].erase(make_tuple(-sz[v], v));
			son[u] = q[u].empty() ? 0 : get<1>(*q[u].begin());
			pa[u] = v;
			sz[v] += sz[u];
			f[v] += f[u];
			q[v].insert(make_tuple(-sz[u], u));
			son[v] = get<1>(*q[v].begin());
			pa[v] = p;
			q[p].erase(make_tuple(-sz[v], u));
			q[p].insert(make_tuple(-sz[v], v));
			son[p] = get<1>(*q[p].begin());
        }
    }
}
