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

int a[2005][2005];

int p[2005][2005], d[2005][2005];

int mov1[4] = {1,0,0,-1}; int mov2[4] = {0,-1,1,0};//xuong trai phai len

int type[300];

pair<int,int> trace[2005][2005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m; cin >> n >> m;

    pair<int,int> s,t;
    for (int i = 1;i <= n;++i){
        string st; cin >> st;
        for (int j = 1;j <= m;++j){
            a[i][j] = st[j - 1];
            if (a[i][j] == 'o'){s = mp(i,j);}
            if (a[i][j] == 'x'){t = mp(i,j);}
            d[i][j] = 1e9;
        }
    }
    type['v'] = 0; type['<'] = 1; type['>'] = 2; type['^'] = 3; type['.'] = -1;
    type['o'] = -1;


    priority_queue<pair<int,pair<int,int>>> q;
    d[s.first][s.second] = 0;
    q.push({0,{s.first,s.second}});
    while (q.size()){
        auto x = q.top();
        q.pop();

        int i = x.second.first; int j = x.second.second;

        if (a[i][j] == 'x') continue;
        if (p[i][j]) continue;
        p[i][j] = 1;
        for (int k = 0;k < 4;++k){
            int u = mov1[k] + i;
            int v = mov2[k] + j;
            if (u > n || u <= 0 || v > m || v <= 0) continue;

            int w = 1 - (type[a[i][j]] == k);

            if (d[u][v] > d[i][j] + w){
                trace[u][v] = mp(i,j);
                d[u][v] = d[i][j] + w;
                q.push({-d[u][v],{u,v}});
            }
        }
    }

    cout << d[t.first][t.second] - 1 << '\n';
    int start = t.first; int en = t.second;
    while (1){
        int temp1 = start; int temp2 = en;
        start = trace[temp1][temp2].first; en = trace[temp1][temp2].second;
        if (a[start][en] == 'o') break;
        if (start - temp1 == -1){a[start][en] = 'v';}
        if (start - temp1 == 1){a[start][en] = '^';}
        if (en - temp2 == -1){a[start][en] = '>';}
        if (en - temp2 == 1){a[start][en] = '<';}
    }

    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= m;++j){
            cout << (char)a[i][j];
        }
        cout << '\n';
    }
}
