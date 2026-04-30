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

int n, h[100005];

ll bit[100005], a[100005];

void update(int i,ll p){
    while (i <= n){
        bit[i] = max(bit[i],p);
        i += (i&(-i));
    }
}
ll get(int p){

    ll res = 0;
    while (p > 0){
        res = max(res,bit[p]);
        p -= (p&(-p));
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    cin >> n;


    for (int i = 1;i <= n;++i) cin >> h[i];
    for (int i = 1;i <= n;++i) cin >> a[i];

    ll ans = 0;
    for (int i = 1;i <= n;++i){
        ll v = a[i] + get(h[i] - 1);
        ans = max(ans,v);
        update(h[i],v);
    }
    cout << ans;
}
