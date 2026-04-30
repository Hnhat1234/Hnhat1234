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

int c[300005];

vector<pair<int,int>> x[300005];
vector<pair<int,int>> y[300005];

pair<int,int> p[300005];

ll f[300005], b[300005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,k; cin >> n >> k;
    for (int i = 1;i <= n;++i){
        int a,b1,val; cin >> a >> b1 >> val;
        p[i] = {a,b1};
        x[a].push_back({b1,i});
        y[b1].push_back({a,i});
        b[i] = val;
    }
    memset(f,-1e9,sizeof(f));
    priority_queue<pair<ll,int>> q;
    f[1] = b[1];
    q.push({f[1],1});
    while (q.size()){
        auto z = q.top(); q.pop();
        int v = z.second; ll g = z.first;
        if (g != f[v]) continue;
        for (auto s:x[p[v].first]){
            if (s.first <= p[v].second){continue;}
            if (g + b[s.second] - k < k){continue;}
            if (f[s.second] < g + b[s.second] - k){
                f[s.second] = g + b[s.second] - k;
                q.push({f[s.second],s.second});
            }
        }
        for (auto x:y[p[v].second]){
            if (x.first <= p[v].first){continue;}
            if (g + b[x.second] - k < k){continue;}
            if (f[x.second] < g + b[x.second] - k){
                f[x.second] = g + b[x.second] - k;
                q.push({f[x.second],x.second});
            }
        }
    }
    cout << f[n];
}
