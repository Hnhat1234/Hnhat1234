#include <bits/stdc++.h>
#define ll long long

using namespace std;

int p[1005];

double d[1005][15];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    vector<vector<pair<int,double>>> adj(1005);
    int n,m,k; cin >> n >> m >> k;
    for (int i = 1;i <= m;++i){
        int x,y; double c; cin >> x >> y >> c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }
    for (int i = 0;i <= n;++i){
        for (int j = 0;j <= k;++j){
            d[i][j] = 1e9;
        }
    }
    for (int i = 0;i <= k;++i){d[1][i] = 0;}
    priority_queue<pair<double,pair<int,int>>> q;

    q.push({d[1][0],{1,0}});
    while (q.size()){
        auto x = q.top(); q.pop();
        double a = -x.first; int cur = x.second.second; int u = x.second.first;
        if (u == n) break;
        if (d[u][cur] < a - (1e-9)) continue;
        for (auto y:adj[u]){
            int v = y.first; double w = y.second;
            for (int i = cur;i <= k;++i){
                double value = a + w * 1.00 / (1 << (i - cur));
                if (d[v][i] > value){
                    d[v][i] = value;
                    q.push({-d[v][i],{v,i}});
                }
            }
        }
    }
    cout << fixed << setprecision(2) << d[n][k];
}
