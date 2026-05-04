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

ll a[100005];

ll f[100005][105][2];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,k; cin >> n >> k;
    for (int i = 1;i <= n;++i) cin >> a[i];


    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= k;++j){
            if (j > i) continue;
            if (i == 1){f[1][1][0] = 0; f[1][1][1] = a[1]; break;}
            f[i][j][0] = max(f[i - 1][j][0],f[i - 1][j - 1][1]);
            f[i][j][1] = max(f[i - 1][j][1] + a[i],max(f[i - 1][j][0] + a[i],f[i - 1][j - 1][1] + a[i]));
        }
    }

    cout << f[n][k][1];
}
