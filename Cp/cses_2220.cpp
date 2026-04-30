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

int f[10][20];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    ll x,y;cin >> x >> y;

    x -= 1;
    for (int k = 1;k <= 19;++k){
        for (int start = 0;start <= 9;++start){
            if (k == 1){f[start][k] = 1; continue;}
            for (int i = 0;i <= 9;++i){
                if (i != start) f[i][k] += f[start][k - 1];
            }
        }
    }

    string a,b;
    while (x != 0){
        a += (char)(x % 10);
        x/=10;
    }
    while (y != 0){
        b += (char)(y % 10);
        y/=10;
    }
    reverse(a.begin(),a.end()); reverse(b.begin(),b.end());

    ll l = 0; ll r = 0;
    for (int i = 0;i < b.size();++i){
        for (int j = 0;j < (b[i] - '0');++j){
            ans += f[j][b.size()];
        }
    }
}
