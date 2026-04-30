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

char a[1005][1005];

int dmon[1005][1005], dplayer[1005][1005];

int x[4] = {1,0,-1,0};

int y[4] = {0,1,0,-1};

char dir[4] = {'D','R','U','L'};

pair<int,pair<int,int>> trace[1005][1005];

void ans(int i,int j,int s,int t){
    string res = "";
    while (i != s || j != t){
        res += dir[trace[i][j].first];

        int temp1 = trace[i][j].second.first;
        int temp2 = trace[i][j].second.second;

        i = temp1; j = temp2;
    }
    reverse(res.begin(),res.end());
    cout << res << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m; cin >> n >> m;
    queue<pair<int,int>> monster;
    queue<pair<int,int>> player;

    int s,t;
    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= m;++j){
            cin >> a[i][j];
            dmon[i][j] = dplayer[i][j] = 1000001;
            if (a[i][j] == 'M'){monster.push({i,j}); dmon[i][j] = 0;}
            if (a[i][j] == 'A'){player.push({i,j}); dplayer[i][j] = 0; s = i; t = j;}
        }
    }

    while (monster.size()){
        pair<int,int> p = monster.front(); monster.pop();
        for (int i = 0;i < 4;++i){
            int dx = p.first + x[i];
            int dy = p.second + y[i];
            if (dx <= 0 || dy <= 0 || dx > n || dy > m){continue;}
            if (a[dx][dy] == '#'){continue;}
            if (dmon[dx][dy] != 1000001){continue;}
            dmon[dx][dy] = dmon[p.first][p.second] + 1;
            monster.push({dx,dy});
        }
    }
    while (player.size()){
        pair<int,int> p = player.front(); player.pop();
        if ((p.first == 1 || p.first == n || p.second == 1 || p.second == m) && (dplayer[p.first][p.second] < dmon[p.first][p.second])){
            cout << "YES" << '\n';
            cout<< dplayer[p.first][p.second] << '\n';
            ans(p.first,p.second,s,t);
            return 0;
        }
        for (int i = 0;i < 4;++i){
            int dx = p.first + x[i];
            int dy = p.second + y[i];
            if (dx <= 0 || dx > n || dy <= 0 || dy > m){continue;}
            if (dplayer[dx][dy] != 1000001){continue;}
            if (a[dx][dy] == '#'){continue;}
            dplayer[dx][dy] = dplayer[p.first][p.second] + 1;
            trace[dx][dy] = {i,{p.first,p.second}};
            player.push({dx,dy});
        }
    }
    cout << "NO";

}
