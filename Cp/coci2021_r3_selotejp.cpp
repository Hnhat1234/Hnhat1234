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

char a[1005][15];

int f[1 << 10], pref[1 << 10];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m; cin >> n >> m;
    for (int i = 0;i < n;++i){
        for (int j = 0;j < m;++j){
            cin >> a[i][j];
        }
    }
    for (int i = 0;i < (1 << m);++i){pref[i] = 1e5;}

    pref[0] = 0;
    for (int i = 0;i < n;++i){
        for (int j = 0;j < m;++j){
            for (int mask = 0;mask < (1 << m);++mask){
                if (getbit(mask,j)){
                    if (a[i][j] == '.'){f[mask] = 100000;}
                    else{
                        f[mask] = min(pref[mask],pref[mask ^ (1 << j)] + 1);
                    }
                }else{
                    if (a[i][j] == '.'){
                        f[mask] = min(pref[mask],pref[mask ^ (1 << j)]);
                    }else if (j && a[i][j] == '#' && a[i][j - 1] == '#' && !getbit(mask,j - 1)){
                        f[mask] = min(pref[mask],pref[mask ^ (1 << j)]);
                    }else{
                        f[mask] = min(pref[mask],pref[mask ^ (1 << j)]) + 1;
                    }
                }
            }
            for (int j = 0;j < (1 << m);++j){pref[j] = f[j];}
        }
    }

    int ans = 100000;
    for (int i = 0;i < (1 << m);++i){
        ans = min(ans,pref[i]);
    }
    cout << ans;
}
