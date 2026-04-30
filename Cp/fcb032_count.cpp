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

const int N = 2e5 + 1;

using namespace std;

vector<int> adj[N];

set<int> s[N];

int n;

void dfs(int u,int p){
    for (int v:adj[u]){
        if (v == p) continue;
        dfs(v,u);
        for (int x:s[v]){
            s[u].insert(x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);
    cin >> n;
    for (int i = 1;i < n;++i){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1;i <= n;++i){int c;cin >> c; s[i].insert(c);}
    dfs(1,0);
    for (int i = 1;i <= n;++i){
        cout << s[i].size() << ' ';
    }
}
