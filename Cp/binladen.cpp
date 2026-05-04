#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<pair<int,int>>> adj(100005);

int d[100005], p[100005];
int main(){
     int n,m; cin >> m >> n;

     for (int i = 1;i <= m;++i){
         for (int j = 1;j <= n;++j){
            int x; cin >> x;
            if (i == 1){
                adj[0].push_back({j,x});
                adj[j].push_back({0,x});
            }
            else{
                adj[(i - 2)*n + j].push_back({(i - 1)*n + j,x});
                adj[(i - 1)*n + j].push_back({(i - 2)*n + j,x});
            }
         }


        for (int j = 1;j < n;++j){
            int x; cin >> x;
            adj[(i - 1)*n + j].push_back({(i - 1)*n + j + 1,x});
            adj[(i - 1)*n + j + 1].push_back({(i - 1)*n + j,x});
        }
     }

     priority_queue<pair<int,int>> q;

     for (int i = 1;i <= n*m;++i){d[i] = 1e9;}

     d[0] = 0;
     q.push({d[0],0});

     while (q.size()){
        auto x = q.top(); q.pop();
        int u = x.second;

        if (p[u]){continue;}
        p[u] = 1;

        for (auto v:adj[u]){
            if (d[v.first] > d[u] + v.second){
                d[v.first] = d[u] + v.second;
                q.push({-d[v.first],v.first});
            }
        }
     }

     cout << d[n * m];
}
