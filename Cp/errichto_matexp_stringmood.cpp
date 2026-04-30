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

ll mod = 1e9 + 7;

struct Matrix{
    ll m[2][2];
    Matrix mul(Matrix a,Matrix b){
        Matrix c;
        c.m[0][0] = c.m[0][1] = c.m[1][1] = c.m[1][0] = 0;
        for (int i = 0;i < 2;++i){
            for (int j = 0;j < 2;++j){
                for (int k = 0;k < 2;++k){
                    (c.m[i][j] += (a.m[i][k] * b.m[k][j])) %= mod;
                }
            }
        }
        return c;
    }
    Matrix fastpow(Matrix a,ll n){
        if (n == 1){return a;}
        Matrix b = fastpow(a,n/2);
        if (n % 2 == 0){
            return mul(b,b);
        }else{
            return mul(a,mul(b,b));
        }
    }
};

Matrix ans;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    ll n; cin >> n;
    ans.m[0][0] = 19; ans.m[0][1] = 6;
    ans.m[1][0] = 7; ans.m[1][1] = 20;

    ans = ans.fastpow(ans,n);
    cout << ans.m[0][0];
}
