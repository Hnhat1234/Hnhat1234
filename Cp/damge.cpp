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

vector<vector<int>> adj(30005);

int vis[30005];

int a[30005];

void dfs(int u){
    if (vis[u] == 2) return;
    vis[u] = 1;
    for (auto v:adj[u]){
        if (vis[v] == 2 || vis[v] == 1) continue;
        dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    int p,c,n; cin >> p >> c >> n;
    for (int i = 0;i < c;++i){
        int a,b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1;i <= n;++i){
        cin >> a[i]; vis[a[i]] = 3;
    }

    for (int i = 1;i <= n;++i){
        for (auto u:adj[a[i]]){
            if (vis[u] == 3) continue;
            vis[u] = 2;
        }
    }

    dfs(1);

    int ans = 0;

    for (int i = 1;i <= p;++i){ans += (vis[i] == 1);}

    cout << p - ans;
}
