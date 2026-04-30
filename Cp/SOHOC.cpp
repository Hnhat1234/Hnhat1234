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

ll gcd(ll a,ll b){
    if (b == 0) return a;
    return gcd(b,a%b);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("SOHOC.INP","r",stdin);
    freopen("SOHOC.OUT","w",stdout);

    ll a,b,x,y; cin >> a >> b >> x >> y;

    ll ans = 0;

    ans = b/x + b/y - b/((x*y)/gcd(x,y));

    if (a > 1){
        ans -= ((a - 1)/x + (a - 1)/y);

        ans += (a - 1)/((x*y)/gcd(x,y));
    }

    cout << ans;
}
