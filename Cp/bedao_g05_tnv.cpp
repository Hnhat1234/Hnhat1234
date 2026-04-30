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

ll a[1000005], pos[1000005];

ll ma[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,q; cin >> n >> q;

    vector<ll> b,p;
    for (int i = 1;i <= n;++i) cin >> a[i];

    for (int i = 1;i <= q;++i){
        int t; cin >> t;
        if (t == 1){
            ll j,x; cin >> j >> x;
            pos[j] = i; a[j] = x;
        }else{
            ll x; cin >> x;
            p.push_back(i);
            b.push_back(x);
        }
    }
    for (int i = b.size() - 1;i >= 0;--i){
        ma[i] = max(ma[i + 1],b[i]);
    }
    for (int i = 1;i <= n;++i){
        ll s = lower_bound(p.begin(),p.end(),pos[i]) - p.begin();
        if (a[i] < ma[s]){cout << ma[s] << ' ';}
        else{cout << a[i] << ' ';}
    }
}
