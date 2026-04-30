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

ll p[200005];

ll dp[3005];

void process(){
    p[0] = 1;
    for (int i = 1;i <= 200000;++i){
        p[i] = p[i - 1] * i; p[i] %= mod;
    }
}
ll fpow(ll a,ll n){
    if (n == 0) return 1LL;
    if (n == 1) return a;
    ll b = fpow(a,n/2);
    if (n % 2 == 0){return (b % mod * b % mod) % mod;}
    else{
        return ((b % mod * b % mod) % mod * a % mod) % mod;
    }
}
ll ckn(ll n,ll k){
    return (p[n] * fpow((p[k] * p[n - k]) % mod,mod - 2)) % mod;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    process();
    ll n,h,w; cin >> h >> w >> n;
    pair<ll,ll> pa[3005];
    for (int i = 1;i <= n;++i){
        cin >> pa[i].first >> pa[i].second;
    }
    sort(pa + 1,pa + 1 + n);
    pa[n + 1] = {h,w};
    for (int i = 1;i <= n + 1;++i){
        ll temp = ckn(pa[i].first + pa[i].second - 2,pa[i].first - 1);
        for (int j = 1;j < i;++j){
            if (pa[i].second >= pa[j].second){
                temp = temp - dp[j] * ckn(pa[i].first + pa[i].second - pa[j].first - pa[j].second,pa[i].first - pa[j].first) % mod;
                temp = (temp + mod) % mod;
            }
        }
        dp[i] = temp;
    }
    cout << dp[n + 1] % mod;
}
