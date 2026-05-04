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

int a[105][105], b[105][105];

int pre[105][105];

int get(int x,int y,int u,int v){
    return pre[u][v] - pre[u][y - 1] - pre[x - 1][v] + pre[x - 1][y - 1];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int m,n,p; cin >> m >> n >> p;

    int cur = 0;
    for (int i = 1;i <= m;++i){
        string s; cin >> s;
        for (int j = 1;j <= n;++j){
            if (s[j - 1] == '0'){
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            }else if (s[j - 1] == '1'){
                cur += 1;
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] - 1;
            }else{
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + 1;
            }
        }
    }
    for (int x = 1;x <= m - p + 1;++x){
        for (int y = 1;y <= n - p + 1;++y){
            int res = cur;
            for (int i = 1;i <= m - p + 1;++i){
                for (int j = 1;j <= n - p + 1;++j){
                    int i1 = i + p - 1; int j1 = j + p - 1;
                    int x1 = x + p - 1; int y1 = y + p - 1;
                    if (x == i && y == j) continue;
                    if (x >= i && x <= i1 && y >= j && y <= j1){
                        res = min(res,cur + get(x,y,x1,y1) + get(i,j,i1,j1) - 2 * get(x,y,i1,j1));
                    }else if (x1 >= i && x1 <= i1 && y1 >= j && y1 <= j1){
                        res = min(res,cur + get(x,y,x1,y1) + get(i,j,i1,j1) - 2 * get(i,j,x1,y1));
                    }else if (x >= i && x <= i1 && y1 >= j && y1 <= j1){
                        res = min(res,cur + get(x,y,x1,y1) + get(i,j,i1,j1) - 2 * get(x,j,i1,y1));
                    }else if (x1 >= i && x1 <= i1 && y >= j && y <= j1){
                        res = min(res,cur + get(x,y,x1,y1) + get(i,j,i1,j1) - 2 * get(i,y,x1,j1));
                    }else{
                        res = min(res,cur + get(x,y,x1,y1) + get(i,j,i1,j1));
                    }
                }
            }
            cout << res << ' ';
        }
        cout << '\n';
    }
}
