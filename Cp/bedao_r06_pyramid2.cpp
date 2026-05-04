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
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    ll mod = 1e9 + 7;

    int q;cin >> q;
    while (q--){
        ll m,n; cin >> n >> m;
        if (m == 1){cout << 1;}
        else{
            ll sum = ((m*(m - 1))/2 - 1)%mod;

            ll ans = (((sum*((n*2)%mod))%mod + (n*m)%mod)%mod + (n + 1)%mod)%mod;
            cout << ans;
        }
        cout << '\n';
    }
}
