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

ll a[1000006];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        ll n,x; cin >> n >> x;

        ll s = 0;
        map<ll,int> m;
        m[0] = 1;

        ll ans = 0;
        for (int i = 1;i <= n;++i){
            cin >> a[i];
            s += a[i];
            ans += m[s - x];
            m[s]++;
        }
        if (ans == 0){cout << "HUHU" << '\n';}
        else cout << ans << '\n';
    }
}
