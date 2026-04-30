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

ll mod = 1e9 + 7;

int a[1005];

ll b[1005];

ll pre[1005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n;cin >> n;
    pair<ll,ll> p[1005];
    for (int i = 1;i <= n;++i){
        cin >> p[i].first >> p[i].second;
    }
    sort(p + 1,p + 1 + n);
    for (int i = 1;i <= n;++i){
        a[i] = p[i].first; b[i] = p[i].second;
        pre[i] = p[i].second + pre[i - 1];
    }

    unsigned ll ans = 0;
    for (int i = 1;i <= n;++i){

        if (p[i].second >= 3){ans = (ans + p[i].second * (p[i].second - 1) * (p[i].second - 2) / 6) % mod;}
        int r1 = lower_bound(a + 1,a + 1 + n,2 * a[i]) - a; r1--;
        if (p[i].second >= 2){
            if (r1 < i) ans = (ans + pre[r1] * b[i] * (b[i] - 1)/2) % mod;
            else ans = (ans + b[i] * (b[i] - 1) / 2 * (pre[i - 1] + pre[r1] - pre[i])) % mod;
        }

        for (int j = i + 2;j <= n;++j){
            int l = upper_bound(a + i + 1,a + j,abs(a[i] - a[j])) - a;
            int r = lower_bound(a + i + 1,a + j,a[i] + a[j]) - a; r--;

            ans = (ans + b[i] * b[j] * (pre[r] - pre[l - 1])) % mod;
        }
    }

    cout << ans;
}
