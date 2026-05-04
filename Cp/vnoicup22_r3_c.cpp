#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<pair<int,pair<int,ll>>>> adj(100005);

int p[100005];

int vis[100005];

int tri = 0;

vector<int> a;

void dfs(int u){
    a.push_back(u);
    vis[u] = 1;

    for (auto v:adj[u]){

        if (p[u] != 0 && p[v.first] != 0){
             int t=0;
             if (p[u] != v.second.second || p[v.first] != v.second.first){t+=1;}
             if (p[u] != v.second.first || p[v.first] != v.second.second){t+=1;}

             if (t == 2){tri += 1; return;}
        }
        else if (p[u] != 0 && p[v.first] == 0){
            if (p[u] != v.second.first && p[u] != v.second.second){
                tri+=1;return;
            }
        }

        if (vis[v.first]){continue;}

        if (v.second.first == p[u]){p[v.first] = v.second.second;}
        else{p[v.first] = v.second.first;}


        dfs(v.first);
    }
}

void dfsc(int u){

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n,m; cin >> n >> m;

    for (int i = 0;i < m;++i){
        int a,b; cin >> a >> b;

        ll x,y;cin >> x >> y;

        adj[a].push_back({b,{x,y}});
        adj[b].push_back({a,{x,y}});
    }

    for (int i = 1;i <= n;++i){
        a.clear();
        if (vis[i] || adj[i].size() == 0){continue;}

        tri = 0;

        for (auto v:adj[i]){
            p[i] = v.second.first; break;
        }
        dfs(i);
        if (tri > 0){
            tri = 0;

            for (auto x:a){
                vis[x] = 0; p[x] = 0;
            }

            for (auto v:adj[i]){
                p[i] = v.second.second; break;
            }

            dfs(i);

            if (tri > 0){cout << -1;return 0;}
        }
    }

    for (int i = 1;i <= n;++i){
        cout << (p[i] > 0 ? p[i] : 1) << ' ';
    }
}
