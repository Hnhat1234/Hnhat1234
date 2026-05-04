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

int n, a[305];

double f[305][305][305];

double dp(int x,int y,int z){
     if (x < 0 || y < 0 || z < 0) return 0;
     if (x == 0 && y == 0 && z == 0) return 0;
     if (f[x][y][z] > 0) return f[x][y][z];

     double p = n + x * dp(x - 1,y,z) + y * dp(x + 1,y - 1,z) + z * dp(x,y + 1,z - 1);
     return f[x][y][z] = p/(x + y + z);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    cin >> n;
    int x = 0; int y = 0; int z = 0;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        if (a[i] == 1){x++;}
        if (a[i] == 2){y++;}
        if (a[i] == 3){z++;}
    }

    memset(f,-1,sizeof f);
    cout << fixed << setprecision(10) << dp(x,y,z);
}
