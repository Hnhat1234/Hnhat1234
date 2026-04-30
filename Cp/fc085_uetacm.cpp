#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
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

ll a[1005][20];

ll c[1 << 16], mx[1 << 16];

int n,k;

ll dequyconho(int i,ll mask1,ll mask2,ll mask3){
    if (i == k){
        return mx[mask1] + mx[mask2] + mx[mask3];
    }
    return max(dequyconho(i + 1,mask1 + (1 << i),mask2,mask3),
    max(dequyconho(i + 1,mask1,mask2 + (1 << i),mask3),dequyconho(i + 1,mask1,mask2,mask3 + (1 << i))));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    cin >> n >> k;

    for (int i = 1;i <= n;++i){
        for (int j = 0;j < k;++j){
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;++i){
        c[0] = 0;
        for (int mask = 1;mask < (1 << k);++mask){
            int x = __builtin_ctz(mask);
            c[mask] = c[mask ^ (1 << x)] + a[i][x];
            mx[mask] = max(mx[mask],c[mask]);
        }
    }
    cout << dequyconho(0LL,0LL,0LL,0LL);
}
