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

ll a[3005];

ll f[3005][3005][2];

ll dp(int l,int r,int type){

    if (f[l][r][type]) return f[l][r][type];

    if (l == r && type == 0){return a[l];}
    else if (l == r && type == 1){return 0LL;}
    else if (type == 0){
        return max(dp(l + 1,r,1) + a[l],dp(l,r - 1,1) + a[r]);
    }
    else if (type == 1){
        return min(dp(l + 1,r,0),dp(l,r - 1,0));
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int n; cin >> n;

    ll s = 0;
    for (int i = 1;i <= n;++i){cin >> a[i]; s += a[i];}

    ll x = dp(1,n,0);
    cout << x - (s - x);

}
