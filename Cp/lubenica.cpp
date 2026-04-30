#include <bits/stdc++.h>
#define ll long long

using namespace std;



vector<vector<pair<ll,ll>>> adj(100005);

ll f_mi[100005][25], f_ma[100005][25];

ll h[100005], p[100005][25];

void dfs(int u,int pa){
    for (auto x:adj[u]){
        ll v = x.first; ll w = x.second;
        if (v == pa){continue;}
        h[v] = h[u] + 1;
        p[v][0] = u;
        f_mi[v][0] = f_ma[v][0] = w;
        dfs(v,u);
    }
}
void quesol(int u,int v){
    if (h[u] < h[v]){swap(u,v);}
    int log = 0;
    for (;1 << log <= h[u];++log){} --log;
    ll mi = 1e9; ll ma = 0;
    for (int i = log;i >= 0;--i){
        if (h[u] - (1 << i) >= h[v]){
            mi = min(mi,f_mi[u][i]);
            ma = max(ma,f_ma[u][i]);
            u = p[u][i];
        }
    }
    if(u != v) {
        for(int i = log; i >= 0; --i)
            if(p[u][i] != p[v][i]) {
                mi = min(mi, min(f_mi[u][i], f_mi[v][i]));
                ma = max(ma, max(f_ma[u][i], f_ma[v][i]));
                u = p[u][i]; v = p[v][i];
            }
        mi = min(mi, min(f_mi[u][0], f_mi[v][0]));
        ma = max(ma, max(f_ma[u][0], f_ma[v][0]));
    }
    cout << mi << ' ' << ma << '\n';
}
void sparetable(int n){
    memset(p,-1,sizeof(p));
    dfs(1,0);
    for(int j = 1; (1 << j) < n; ++j)
        for(int u = 1; u <= n; ++u)
            if(p[u][j - 1] != -1){
                p[u][j] = p[p[u][j - 1]][j - 1];
                f_mi[u][j] = min(f_mi[u][j - 1], f_mi[p[u][j - 1]][j - 1]);
                f_ma[u][j] = max(f_ma[u][j - 1], f_ma[p[u][j - 1]][j - 1]);
            }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;

    for (int i = 1;i < n;++i){
        ll a,b,l; cin >> a >> b >> l;

        adj[a].push_back({b,l});
        adj[b].push_back({a,l});
    }

    sparetable(n);
    int t; cin >> t;
    while (t--){
       int u,v; cin >> u >> v;
       quesol(u,v);
    }
}

