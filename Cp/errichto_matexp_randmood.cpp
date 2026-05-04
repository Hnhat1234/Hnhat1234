#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct Matrix{
    double m[3][3];

    Matrix identity(int n){
        Matrix a;
        for (int i = 1;i <= 2;++i){a.m[i][i] = 1;}
        return a;
    }

    Matrix mul(const Matrix &a,const Matrix &b){
        Matrix c;
        for (int i = 1;i <= 2;++i){
            for (int j = 1;j <= 2;++j){
                for (int k = 1;k <= 2;++k){
                    c.m[i][j] += a.m[i][k] * b.m[k][j];
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
        if (n % 2 == 0){return mul(fast_pow(a,x),fast_pow(a,x));}
        else{return mul(mul(fast_pow(a,x),fast_pow(a,x)),a);}
    }
};

Matrix ans;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    ll n; cin >> n;
    double p; cin >> p;
    ans.m[1][1] = p; ans.m[1][2] = 1.00 - p;
    ans.m[2][1] = 1.00 - p; ans.m[2][2] = p;

    ans = ans.fast_pow(ans,n - 1);
    if (n % 2 == 0){cout << ans.m[1][1] * p + ans.m[1][2] * (1 - p);}
    else{cout << 1 - (ans.m[1][1] * p + ans.m[1][2] * (1 - p));}
}
