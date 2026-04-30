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

int p[100005];

ll f[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);
    int n,m; cin >> n >> m;
    for (int i = 1;i <= m;++i){
        ll a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    f[1] = 0;
    for (int i = 2;i <= n;++i){f[i] = 1e18;}
    priority_queue<pair<ll,int>> q;
    q.push({f[1],1});
    while (q.size()){
        auto a = q.top(); q.pop();
        int u = a.second;
        if (p[u]) continue;
        p[u] = 1;

        for (auto x:adj[u]){
            int v = x.first;
            ll w = x.second;

            if (f[v] > f[u] + w){
                f[v] = f[u] + w;
                q.push({-f[v],v});
            }
        }
    }
    for (int i = 1;i <= n;++i) cout << f[i] << ' ';
}
