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

int s1[4] = {1,-1,0,0};

int s2[4] = {0,0,1,-1};

int n, a[1005][1005];

int d[1005][1005][5];

int res; int s,t;

map<int,map<int,int>> m;

void dfs(int x,int y,int p){
    for (int i = 0;i < 4;++i){
        int dx = x + s1[i]; int dy = y + s2[i];
        if (d[x][y][i]) continue;
        if (dx > n || dy > n || dx <= 0 || dy <= 0) continue;
        if (p != abs(a[x][y] - a[dx][dy])) continue;

        res += (m[dx][dy] == 0); m[dx][dy] = 1;
        d[x][y][i] = d[dx][dy][i + ((i % 2 == 0) - (i % 2 != 0))] = 1;
        dfs(dx,dy,p);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int ans = 0;

    cin >> n;

    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= n;++j){
            cin >> a[i][j];
        }
    }

    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= n;++j){
            m[i][j] = 1; res = 1; dfs(i,j,abs(a[i][j] - a[i - 1][j])); ans = max(ans,res); m.clear();
            m[i][j] = 1; res = 1; dfs(i,j,abs(a[i][j] - a[i + 1][j])); ans = max(ans,res); m.clear();
            m[i][j] = 1; res = 1; dfs(i,j,abs(a[i][j] - a[i][j - 1])); ans = max(ans,res); m.clear();
            m[i][j] = 1; res = 1; dfs(i,j,abs(a[i][j] - a[i][j + 1])); ans = max(ans,res); m.clear();
        }
    }
    cout << ans;
}
