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

const ll basehash = 31;
const ll modhash = 1000000003;

ll a[200005], vis[35];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 1;i <= n;++i){cin >> a[i];}

        ll ans = 0;
        for (int i = 0;i < min(31,n);++i){
            ll mx = 0; ll pos = 0;
            for (int j = 1;j <= n;++j){
                if (vis[j]) continue;

                if ((ans | a[j]) > mx){mx = ans | a[j]; pos = j;}
            }
            vis[pos] = 1;
            cout << a[pos] << ' ';
            ans |= a[pos];
        }
        for (int i = 1;i <= n;++i){
            if (!vis[i]){cout << a[i] << ' ';}
            vis[i] = 0;
        }
        cout << '\n';
    }
}
