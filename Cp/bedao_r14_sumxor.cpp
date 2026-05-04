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

ll pw[65];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    pw2[0] = 1;
    for (int i = 1;i <= 63;++i){pw2[i] = pw2[i - 1] * 2LL;}
    int t; cin >> t;
    while (t--){
        ll l,r; cin >> l >> r;

        ll ans = 0;
        for (int i = 0;i <= 62;++i){
            if (pw2[i] > r) break;
            if (i == 0){
                ll y = min(pw2[63], r - ) - pw2[i + 1];
            }
        }
    }
}
