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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    ll l,r; cin >> l >> r;

    ll ans = 0;
    for (ll i = 1;i <= 100000;++i){
        if (i < 10 && (i >= l && i <= r)){ans += i;}
        ll temp = i; ll res = i;
        while (temp != 0){
            res = (res * 10 + temp % 10);
            temp/=10;
        }
        if (res >= l && res <= r){ans += res;}
        for (int j = 0;j <= 9;++j){
            res = i;
            res = (res * 10 + j);
            temp = i;
            while (temp != 0){
                res = (res * 10 + temp % 10);
                temp/=10;
            }
            if (res >= l && res <= r){ans += res;}
        }
    }
    cout << ans;
}
