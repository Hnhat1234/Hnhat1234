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

ll a[1005][1005], d[1005][1005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m; cin >> n >> m;
    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= m;++j){
            cin >> a[i][j];
        }
    }

    ll l = 1; ll r = 1e9;
    while (l <= r){
        ll mid = (l + r)/2;
        for (int i = 1;i <= n;++i){
            for (int j = 1;j <= m;++j){
                d[i][j] = 0;
            }
        }
        d[1][1] = 0; d[1][0] = mid;
        for (int i = 1;i <= n;++i){
            for (int j = 1;j <= m;++j){
                if (i == 1 && d[i][j - 1] == 0){continue;}
                else if (i == 1 && d[i][j - 1] <= a[i][j]){d[i][j] = 0;}
                else if (i == 1){
                    d[i][j] = d[i][j - 1] + a[i][j];
                }else{
                    d[i][j] = max(d[i][j - 1],d[i - 1][j]);
                    if (d[i][j] <= a[i][j]){d[i][j] = 0;}
                    else d[i][j] += a[i][j];
                }
            }
        }
        if (d[n][m]){r = mid - 1;}
        else{
            l = mid + 1;
        }
    }
    cout << l;
}
