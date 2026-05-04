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

vector<vector<int>> adj(105);

int s[105];

int a[105][105];

pair<double,double> p[105];

double ans[105];

int c[105];

double mu2(double x){
    return x * x;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);
    int n; cin >> n;
    for (int i = 1;i <= n;++i){
        ans[i] = 1e9;
        cin >> p[i].first >> p[i].second >> s[i];
        for (int j = 1;j < n;++j){
            cin >> a[i][j];
            adj[i].push_back(a[i][j]);
        }
    }
    priority_queue<pair<double,int>> q;
    ans[1] = 0;
    q.push({ans[1],1});
    while (q.size()){
        auto l = q.top(); q.pop();
        int u = l.second;
        if (c[u]) continue;
        c[u] = 1; int track = 1;
        for (int i = 1;i < n && track <= s[u];++i){
            int v = a[u][i];
            double w = 1.00 * sqrt(mu2(p[u].first - p[v].first) + mu2(p[u].second - p[v].second));
            if (c[v]) continue;
            if (ans[v] > ans[u] + w){
                ans[v] = ans[u] + w;
                q.push({-ans[v],v});
            }
            track++;
        }
    }
    for (int i = 1;i <= n;++i){
        cout << setprecision(6) << fixed << ans[i] << '\n';
    }
}
