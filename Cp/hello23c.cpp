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

vector<ll> a,b,c;

vector<pair<ll,int>> d;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    ll n,k; cin >> n >> k;

    for (int i = 1;i <= n;++i){
        ll x,d1; cin >> x >> d1;

        if (d1 % 3 == 0) a.push_back(x); d.push_back({x,0});
        if (d1 % 3 == 1) b.push_back(x);
        if (d1 % 3 == 2) c.push_back(x);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    for (int i = 0;i < sz(b) - 2;++i){
        d.push_back({b[i] + b[i + 1] + b[i + 2],1});
    }
    for (int i = 0;i < sz(c) - 2;++i){
        d.push_back({c[i] + c[i + 1] + c[i + 2],2});
    }

}
