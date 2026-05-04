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

vector<int> adj[200005];

int p[200005][20], euler[400005];

int f[200005], h[200005];

int st[200005], en[200005];

int sz;

void dfs(int u,int par){
    euler[++sz] = u;
    st[u] = sz;

    for (auto v:adj[u]){
        if (v == par){continue;}
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v,u);
    }

    en[u] = sz;
}
void sparetable(int n){
    memset(p,-1,sizeof(p));
    dfs(1,0);
    for (int j = 1; (1 << j) < n;++j){
        for (int u = 1;u <= n;++u){
            if (p[u][j - 1] != -1){
                p[u][j] = p[p[u][j - 1]][j - 1];
            }
        }
    }
}
void lca(int u,int v){
    f[u]++; f[v]++;
    if (h[u] < h[v]){swap(u,v);}
    int log = 0;
    for (;1 << log <= h[u];++log){} --log;

    for (int i = log;i >= 0;--i){
        if (h[u] - (1 << i) >= h[v]){
            u = p[u][i];
        }
    }
    if(u != v){
        for(int i = log; i >= 0; --i)
            if(p[u][i] != p[v][i]){
                u = p[u][i]; v = p[v][i];
        }
        u = p[u][0];
    }
    f[u] -= 2;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    for (int i = 1;i < n;++i){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    h[1] = 1;
    sparetable(n);

    int m; cin >> m;
    while (m--){
        int u,v; cin >> u >> v;
        lca(u,v);
    }

    int ans = 0;
    for (int i = n;i >= 2;--i){
        int u = euler[i];
        for (auto v:adj[u]){
            if (v != p[u][0]){
                f[u] += f[v];
            }
        }
        if (!f[u]){ans++;}
    }
    cout << ans;
}
