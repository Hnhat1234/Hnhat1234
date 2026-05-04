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

int a[500005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    int n; cin >> n;

    int mx = 0;
    for (int i = 1;i <= n;++i){cin >> a[i]; mx = max(mx,a[i]);}

    int h = 0;
    sort(a + 1,a + 1 + n);
    for (int i = 1;i <= n;++i){
        int p = lower_bound(a + 1,a + 1 + n,i) - a;
        if (n - p + 1 >= i){h = max(h,i);}
    }
    cout << h;
}
