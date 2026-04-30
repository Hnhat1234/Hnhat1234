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

vector<pair<int,ll>> adj[100005];

vector<pair<int,ll>> adj2[100005];

pair<pair<int,int>,ll> p[200005];

ll d1[100005], d2[100005];

int check1[100005], check2[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m; cin >> n >> m;
    for (int i = 1;i <= m;++i){
        int a,b; ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj2[b].push_back({a,c});
        p[i] = {{a,b},c};
    }


   for (int i = 1;i <= 100000;++i){d1[i] = d2[i] = 1e18;}

    priority_queue<pair<ll,int>> q;

    d1[1] = 0;
    q.push({d1[1],1});
    while (q.size()){
        auto x = q.top(); q.pop();
        int v = x.second;
        if (check1[v]){continue;}
        check1[v] = 1;
        for (auto g:adj[v]){
            int u = g.first;
            ll w = g.second;
            if (d1[u] > d1[v] + w){
                d1[u] = d1[v] + w;
                q.push({-d1[u],u});
            }
        }
    }
    d2[n] = 0;
    q.push({d2[n],n});
    while (q.size()){
        auto x = q.top(); q.pop();
        int v = x.second;
        if (check2[v]){continue;}
        check2[v] = 1;
        for (auto g:adj2[v]){
            int u = g.first;
            ll w = g.second;
            if (d2[u] > d2[v] + w){
                d2[u] = d2[v] + w;
                q.push({-d2[u],u});
            }
        }
    }
    ll ans = 1e18;
    for (int i = 1;i <= m;++i){
        ans = min(ans,d1[p[i].first.first] + d2[p[i].first.second] + p[i].second/2);
    }
    cout << ans;
}
