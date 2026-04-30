#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod=1e9+7;

ll f[100005];

ll res=0;

vector<vector<pair<int,ll>>> adj(100005);

void dfs(int u,int p){
    for (auto d:adj[u]){
         if (d.first==p){continue;}
         dfs(d.first,u);
         res=(res+f[d.first])%mod;
         res=(res+(((f[d.first+1])*d.second)%mod)*f[u])%mod;
         f[u]+=d.second*(f[d.first]+1);
         f[u]%=mod;
     }
}
int main(){
    int n;cin >> n;
    for (int i=1;i<n;++i){
        int a,b;ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    dfs(1,0);
    cout << (res+f[1])%mod;
}
