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

ll a[205][105];

ll pre[205][205];

ll get(int x,int y,int u,int v){
    return pre[u][v] - pre[u][y - 1] - pre[x - 1][v] + pre[x - 1][y - 1];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int m,n,t; cin >> m >> n >> t;

    int cur = 0;
    for (int i = 1;i <= m;++i){
        for (int j = 1;j <= n;++j){
            cin >> a[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    while (t--){
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        cout << get(x,y,u,v) << '\n';
    }
}
