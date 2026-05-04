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

#define ii pair<int, long long>

using namespace std;

vector<vector<ii>> adj(100005);

int c[100005];

void dfs(int u,int p){
    for (auto x:adj[u]){
        int v = x.first; int w = x.second;
        if (v == p) continue;
        if (w % 2 == 0){c[v] = c[u];}
        else{c[v] = 1 - c[u];}
        dfs(v,u);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    int n; cin >> n;
    c[1] = 0;
    for (int i = 1;i < n;++i){
        ll a,b,w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    dfs(1,0);
    for (int i = 1;i <= n;++i) cout << c[i] << ' ';
}
