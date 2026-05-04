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

ll mul(ll x, ll y){
    return x * y % mod;
}

ll binpow(ll x, ll y){
    ll z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

ll inv(ll x)
{
    return binpow(x,mod - 2);
}

ll divide(ll x, ll y)
{
    return mul(x, inv(y));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    ll mod = 1e9 + 7;
    ll n0,n1,n2; cin >> n0 >> n1 >> n2;

    ll ans = 0;

    ll n = n0 + n1 + n2;

    if (n0 > n1 && (1 + (n0 - n1) * 2 + 3 * n1 == n) && (n0 + 1 == n2)){

        ll k = (n0 - n1); ll n = (n2 - 1);

        ans = 1;
        for (int i = 1;i <= (n - k);++i){
            ans = mul(ans,divide(k + i,i));
        }

        for (int i = 1;i <= n1;++i){ans = (ans * 2LL) % mod;}

    }else if (n0 == n1 && 1 + 2 * n0 == n && (n0 + 1 == n2)){
        ans = 1;
        while (n0--){ans = (ans * 2LL) % mod;}
    }

    cout << ans;
}
