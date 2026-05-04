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

const ll maxn = 200005;
const ll sqr = 635;

ll a[maxn], b[maxn];

ll fr[sqr][maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        ll ans = 0;
        ll lim = sqrt(n * 2);
        for(ll i = 0;i < n;++i){
            cin >> a[i];
        }
        for(ll i=0;i<n;i++){
            cin >> b[i];
            if(a[i] <= lim){fr[a[i]][b[i]]++;}
        }
        for(ll i = 0;i < n;++i){
            if(a[i] <= lim){
                if(a[i] * a[i] - b[i] >= 1 && a[i] * a[i] - b[i] <= n){ans += fr[a[i]][a[i] * a[i] - b[i]];}
            }
        }
        for(ll i = 2;i <= lim;i += 2){ans -= fr[i][i * i / 2];}

        ans /= 2;

        for(ll i = 0;i < n;++i){
            for(ll j = 1;j <= lim && j < a[i] && j * a[i] <= 2 * n;++j){
               if(j * a[i] - b[i] >= 1 && j * a[i] - b[i] <= n){ans += fr[j][j * a[i] - b[i]];}
            }
        }
        for (int i = 0;i < n;++i){
            if (a[i] <= lim){fr[a[i]][b[i]] = 0;}
        }
        cout << ans <<'\n';
    }
}
