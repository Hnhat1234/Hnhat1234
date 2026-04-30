#include <bits/stdc++.h>
#define ll long long
#define piii pair<int,pair<int,int>>

using namespace std;

ll f[105][100005];
int main(){
    int t;cin >> t;
    while (t--){
     vector<vector<piii>> adj(105);
     int k,n,m;
     cin >> k >> n >> m;
     for (int i=0;i<m;++i){
         int a,b,d,c;
         cin >> a >> b >> d >> c;
         adj[a].push_back({b,{d,c}});
     }
     priority_queue<piii,vector<piii>,greater<piii>> q;
     q.push({0,{1,0}});
     for (int i=1;i<=n;++i){
         for (int j=0;j<=k;++j){f[i][j]=1e12;}
     }
     f[1][0]=0;
     int ans=-1;
     while (q.size()){
         auto p=q.top();q.pop();
         if (p.first!=f[p.second.first][p.second.second]){continue;}
         if (p.second.first==n){ans=p.first;break;}
         for (auto x:adj[p.second.first]){
             if (x.second.second + p.second.second <= k && f[p.second.first][p.second.second]+x.second.first < f[x.first][x.second.second + p.second.second]){
                 q.push({f[p.second.first][p.second.second]+x.second.first,{x.first,x.second.second + p.second.second}});
                 f[x.first][x.second.second + p.second.second]=f[p.second.first][p.second.second]+x.second.first;
             }
         }
    }
    cout << ans << '\n';
}
}
