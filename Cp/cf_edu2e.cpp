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

vector<vector<int>> adj(100005);

ll c[100005],mx[100005],ans[100005];

void dfs(int u,int p,map<int,int> &m1){
    ans[u] = c[u];
    mx[u] = 1;
    m1[c[u]]++;

    for (auto v:adj[u]){
        if (v == p) continue;
        map<int,int> m2;
        dfs(v,u,m2);
        if (sz(m2) > sz(m1)){
            swap(m1,m2);
            ans[u] = ans[v];
            mx[u] = mx[v];
        }

        for (auto x:m2){
            m1[x.first] += x.second;
            if (m1[x.first] > mx[u]){
                mx[u] = m1[x.first];
                ans[u] = x.first;
            }else if (m1[x.first] == mx[u]){
                ans[u] += x.first;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //ditmemay
    int n; cin >> n;
    for (int i = 1;i <= n;++i) cin >> c[i];

    for (int i = 1;i < n;++i){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<int,int> m;
    dfs(1,0,m);
    for (int i = 1;i <= n;++i){cout << ans[i] << ' ';}
}
