#include <bits/stdc++.h>

using namespace std;

int c[205];

int f[205][205];

vector<vector<int>> adj(205);

void dfs(int u,int p){
    for (auto v:adj[u]){
        if (v==p){continue;}
        dfs(v,u);
        for (int i=1;i<=p;++i){
            for (int j=p;j>=0;--j){
                if (i >= j){
                    f[u][i]=max(f[u][i],f[v][j]+f[u][i-j]);
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,p;cin >> n >> p;
    for (int i=1;i<=n;++i){cin >> c[i];}
    for (int i=1;i<n;++i){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        f[a][1]=c[a];f[b][1]=c[b];
    }
    int ans=0;
    for (int i=1;i<=n;++i){
        dfs(i,0);
        for (int i=1;i<=n;++i){
            ans=max(ans,f[i][p]);
            for (int j=0;j<=p;++j){
                f[i][j]=0;
            }
            f[i][1]=c[i];
        }
    }
    cout << ans;
}
