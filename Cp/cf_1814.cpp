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

int vis[2005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        vector<int> adj[2005];
        int n,m; cin >> n >> m;
        for (int i = 1;i <= m;++i){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int check = 0;
        for (int i = 1;i <= n;++i){
            if (adj[i].size() < 4){continue;}
            queue<pair<int,int>> q;
            q.push({i,0});
            while (q.size() && check == 0){
                int u = q.front().first;
                int d = q.front().second;
                if (u == i && d >= 3){check = 1; break;}
                q.pop();
                if (vis[u]){continue;}
                vis[u] = 1;
                for (auto v:adj[u]){
                    q.push({v,d + 1});
                }
            }
            for (int i = 1;i <= n;++i){vis[i] = 0;}
        }
        cout << (check ? "YES" : "NO") << '\n';
    }
}
