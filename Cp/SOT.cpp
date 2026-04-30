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
    freopen("SOT.INP","r",stdin);
    freopen("SOT.OUT","w",stdout);

    ll n,m,t; cin >> n >> m >> t;

    ll cur = 0;
    for (int i = 0;i < m;++i){
        if (cur + (n - i)/m + (i > 0) >= t){
            cout << (t - cur - (i > 0))*m + i;

            return 0;
        }else{
            cur += (n - i)/m + (i > 0);
        }
    }
}
