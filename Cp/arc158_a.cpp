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
    int t; cin >> t;
    while (t--){
        ll x1,x2,x3;
        cin >> x1 >> x2 >> x3;
        if ((x1 + x2 + x3) % 3 != 0){cout << -1;}
        else if ((x1 + x2) % 2 == 1 || (x1 + x3) % 2 == 1 || (x2 + x3) % 2 == 1){cout << -1;}
        else{
            ll a = (x1 + x2 + x3)/3;
            cout << (abs(x1 - a) + abs(x2 - a) + abs(x3 - a))/4;
        }
        cout << '\n';
    }
}
