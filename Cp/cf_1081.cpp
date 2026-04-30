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

const ll basehash = 31;
const ll modhash = 1000000003;

int x[100005], par[100005], sz;

vector<pair<ii,ll>> adj;

bool cmp(pair<ii,ll> a,pair<ii,ll> b){
    return a.second < b.second;
}
int Find(int u){
    if (u == par[u]){return u;}
    return par[u] = Find(par[u]);
}
void join(int u,int v,ll c,int k){
    u = Find(u);
    v = Find(v);
    if (u != v){
        if (x[u]){par[v] = u;}
        else{par[u] = v;}

        if (x[u] && x[v]){sz--;}
        if (sz == 1){
            for (int i = 1;i <= k;++i){cout << c << ' ';}
            exit(0);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m,k; cin >> n >> m >> k;
    sz = k;
    for (int i =1;i <= n;++i){par[i] = i;}
    for (int i = 1;i <= k;++i){
        int node; cin >> node;
        x[node] = 1;
    }

    for (int i = 1;i <= m;++i){
        ll u,v,c; cin >> u >> v >> c;
        adj.push_back({{u,v},c});
    }
    sort(adj.begin(),adj.end(),cmp);
    for (int i = 1;i <= m;++i){
        join(adj[i - 1].first.first,adj[i - 1].first.second,adj[i - 1].second,k);
    }
}
