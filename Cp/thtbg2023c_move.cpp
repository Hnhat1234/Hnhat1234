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

ll mod = 2004010501;

char a[1005][1005], check[1005][1005];

ll f[1005][1005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int m,n,k; cin >> m >> n >> k;
    for (int i = 0;i < m;++i){
        for (int j = 0;j < n;++j){
            cin >> a[i][j];
            if (a[i][j] == '#'){check[i][j] = 1;}
        }
    }
    f[0][0] = 1;
    for (int i = 0;i < m;++i){
        for (int j = 0;j < n;++j){
            if (i + j == 0) continue;
            if (check[(i + i) % m][(j + j) % n]){continue;}

            int x = i - 1; int y = j;
            if (x >= 0 && !check[(x + i) % m][(y + j) % n]){
                f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
            }
            x = i; y = j - 1;
            if (y >= 0 && !check[(x + i) % m][(y + j) % n]){
                f[i][j] = (f[i][j] + f[i][j - 1]) % mod;
            }
        }
    }
    cout << f[m - 1][n - 1];
}
