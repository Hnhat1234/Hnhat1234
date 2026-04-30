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

ll arr[300005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    int n; cin >> n;

    ll s = 0;
    for (int i = 1;i <= n;++i){cin >> arr[i]; s += arr[i];}
    if (s == 0){cout << 0 << '\n' << 100; return 0;}

    sort(arr + 1,arr + 1 + n,greater<ll>());

    double a = 0; double b = 0;

    ll temp = 0;
    for (int i = 1;i <= n;++i){
        temp += arr[i];
        double x = i * 100.00/n;
        double y = temp * 100.00/s;

        if ((y - x)*1.00 >= (b - a)*1.00){
            a = x; b = y;
        }
    }

    cout << a << '\n' << b;
}
