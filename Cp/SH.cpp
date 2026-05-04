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

ll a[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("SH.INP","r",stdin);
    freopen("SH.OUT","w",stdout);

    int n; cin >> n;

    for (int i = 1;i <= n;++i) cin >> a[i];

    ll min1 = 1e5; ll min2 = 1e5;

    min1 = min(min1,a[1]);

    if (a[1] < 0){min2 = min(min2,a[1]);}

    ll ans = 1e9;
    for (int i = 2;i <= n;++i){
        if (a[i] >= 0){
            if (a[i] > min1){ans = min(ans,a[i] * min1);}
        }else{
            if (a[i] > min2){ans = min(ans,a[i] * min2);}
            min2 = min(min2,a[i]);
        }
        min1 = min(min1,a[i]);
    }

    if (ans == 1e9){cout << "NO";}
    else cout << ans;
}
