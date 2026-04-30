#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll d[105][105];

int trace[105][105];

int main(){
    vector<vector<pair<int,int>>> adj(100005);
    int n, m, k ;cin >> n >> m >> k;

    for (int i = 1;i <= m;++i){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});

        d[a][b]=c; d[b][a]=c;
    }

    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= n;++j){
            if (i == j){d[i][j] = 0;}
            else if (d[i][j] == 0){d[i][j] = 1e9;}
            trace[i][j] = i;
        }
    }

    for (int k=1;k<=n;++k){
        for (int u=1;u<=n;++u){
            for (int v=1;v<=n;++v){
                if (d[u][v] > d[u][k] + d[k][v]){
                    d[u][v]=d[u][k]+d[k][v];
                    trace[u][v] = trace[k][v];
                }
            }
        }
    }

    while (k--){
        int t,u,v; cin >> t >> u >> v;
        if (t == 0){cout << d[u][v];}
        else{
            vector<int> path;
            while (v != u){
                path.push_back(v);
                v = trace[u][v];
            }

            path.push_back(u);
            cout << path.size() << ' '; for (int i = path.size() - 1;i >= 0;--i){cout << path[i] << ' ';}

        }
        cout << '\n';
    }
}
