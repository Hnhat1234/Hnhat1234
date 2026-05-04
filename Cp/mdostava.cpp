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

int a[2005][205],pos[200005];

int pre[2005][205];

int dp[2005][2005][2];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int r,c; cin >> r >> c;
    for (int i = 1;i <= r;++i){
        for (int j = 1;j <= c;++j){
            cin >> a[i][j];
            pre[i][j] += pre[i][j - 1] + a[i][j];
        }
    }
    int d; cin >> d;
    for (int i = 1;i <= d;++i){cin >> pos[i];}
    for (int i = 2;i <= r;++i){

    }

}
