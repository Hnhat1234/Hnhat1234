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

int n;

struct Matrix{
    ll m[55][55] = {0};

    Matrix identity(int n){
        Matrix a;
        for (int i = 1;i <= n;++i){a.m[i][i] = 1;}
        return a;
    }

    Matrix mul(const Matrix &a,const Matrix &b){
        Matrix c;
        for (int i = 1;i <= n;++i){
            for (int j = 1;j <= n;++j){
                for (int k = 1;k <= n;++k){
                    c.m[i][j] += a.m[i][k] * b.m[k][j];
                    c.m[i][j] %= mod;
                }
            }
        }
        return c;
    }
    Matrix fast_pow(Matrix a,ll n){
        if (n == 0){
            Matrix b = identity(2);
            return b;
        }
        if (n == 1){
            return a;
        }
        ll x = n/2;
        Matrix b = fast_pow(a,x);
        if (n % 2 == 0){return mul(b,b);}
        else{return mul(mul(b,b),a);}
    }
};

Matrix b;

int a[55][55];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    ll k; cin >> n >> k;
    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= n;++j){
            cin >> a[i][j];
            b.m[i][j] = a[i][j];
        }
    }

    ll ans = 0;
    b = b.fast_pow(b,k);
    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= n;++j){
            ans += b.m[i][j];
            ans %= mod;
        }
    }
    cout << ans;
}
