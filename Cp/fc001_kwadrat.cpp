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
    // freopen("Hnhatn.inp","r",stdin);

    ll n; cin >> n;

    ll temp = n;

    map<ll,ll> uocso;
    ll q = sqrt(n);

    for (int i = 2;i <= q;++i){
        while (n % i == 0){
            uocso[i]++;
            n/=i;
        }
    }

    if (n != 1){uocso[n]++;}
    for (auto x:uocso){
        if (x.second % 2 != 0) temp *= x.first;
    }
    cout << temp;
}
