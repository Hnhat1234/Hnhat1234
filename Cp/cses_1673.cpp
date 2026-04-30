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

vector<pair<pair<int,int>,ll>> adj;

vector<int> p[2505];

int vis[2505];

ll d[2505];

ll inf = 1e18;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m; cin >> n >> m;

    for (int i = 1;i <= n;++i){d[i] = inf;}

    for (int i = 1;i <= m;++i){
        ll a,b,x; cin >> a >> b >> x;
        adj.push_back({{a,b},-x});
        p[b].push_back(a);
    }

    d[1] = 0;
    for (int i = 1;i < n;++i){
        for (int j = 0;j < m;++j){
            int u = adj[j].first.first;
            int v = adj[j].first.second;

            ll w = adj[j].second;
            if (d[u] != inf && d[v] > d[u] + w){
                d[v] = d[u] + w;
            }
        }
    }

    queue<int> q; q.push(n);
    while (q.size()){
        int u = q.front(); q.pop();
        if (vis[u]){continue;}
        vis[u] = 1;
        for (auto v:p[u]){
            if (vis[v]){continue;}
            q.push(v);
        }
    }
    q.push(n);
    for (int j = 0;j < m;++j){
        int u = adj[j].first.first;
        int v = adj[j].first.second;

        ll w = adj[j].second;
        if (d[u] != inf && d[v] > d[u] + w){
            if (vis[v]){cout << -1; return 0;}
        }
    }

    cout << -d[n];
}
