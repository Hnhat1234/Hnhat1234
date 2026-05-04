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

int h[1000005], j[1000005];

int ans[1000005], a[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    for (int i = 1;i <= n;++i){cin >> h[i];}
    for (int i = 1;i <= n;++i){cin >> j[i];}

    ans[n] = -1;

    int dem = 0;
    a[dem++] = h[n];
    for (int i = n - 1;i >= 1;--i){
        while (dem > 0 && a[dem - 1] <= h[i]){dem--;}
        if (j[i] > dem){ans[i] = -1;}
        else{ans[i] = a[dem - j[i]];}

        a[dem++] = h[i];
    }

    for (int i = 1;i <= n;++i){cout << ans[i] << ' ';}
}
