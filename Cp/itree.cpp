#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<pair<int,int>> adj[1005];

int d[1005];

void dfs(int u){
    if (!adj[u].size() && u!=1){d[u] = 1e9;}
    else{d[u] = 0;}

    for (auto x:adj[u]){
        int v = x.first; int c = x.second;

        dfs(v);

        d[u] += min(d[v],c);
    }

}
int main(){
     int t;cin >> t;
     while (t--){
        int n;cin >> n;

        for (int i = 2;i <= n;++i){
            int u,c;cin >> u >> c;
            adj[u].push_back({i,c});
        }

        dfs(1);

        cout << d[1] << ".00";

        cout << '\n';

        for (int i = 1;i <= n;++i){adj[i].clear();}
     }
}
