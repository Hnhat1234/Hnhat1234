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

unordered_map<ll,ll> m;

ll suf[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    vector<ll> b;

    b.push_back(0);

    int n; cin >> n;
    for (int i = 1;i <= n;++i){
        ll x,y; cin >> x >> y;
        b.push_back(x/2);
        if (m[x/2] < y/2) m[x/2] = y/2;
    }

    sort(b.begin(),b.end());

    for (int i = n;i >= 1;--i){
        suf[i] = max(suf[i + 1],m[b[i]]);
    }

    ll ans = 0;
    for (int i = 1;i <= n;++i){
        ans += (b[i] - b[i - 1]) * suf[i];

    }

    cout << 4 * ans;
}
