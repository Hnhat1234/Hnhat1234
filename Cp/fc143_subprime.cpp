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

ll prime[1000005], l[1000005], r[1000005];

ll a[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,step; cin >> n >> step;

    for (int i = 2;i <= 1000000;++i) prime[i] = 1;

    for (int i = 2;i <= 1000;++i){
        if (!prime[i]) continue;
        for (int j = i * i;j <= 1000000;j += i){
            prime[j] = 0;
        }
    }
    for (int i = 1;i <= n;++i) cin >> a[i];

    for (int i = 1;i <= n;++i){
        if (a[i] != 1){l[i] = 0; continue;}
        else if (i <= step){l[i] = 1;}
        else{
            l[i] = l[i - step] + 1;
        }
    }
    for (int i = n;i >= 1;--i){
        if (a[i] != 1){r[i] = 0; continue;}
        else if (i > n- step){r[i] = 1;}
        else{
            r[i] = r[i + step] + 1;
        }
    }

    ll ans = 0;
    for (int i = 1;i <= n;++i){
        if (prime[a[i]]) ans += (l[max(i - step,0)] + 1) * (r[min(i + step,n + 1)] + 1) - 1;
    }
    cout << ans;
}
