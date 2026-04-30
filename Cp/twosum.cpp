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

ll pre[5005], pos[5005];

ll a[5005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;

    int ans = 0;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1;i <= n;++i){
        ll s = 0;
        for (int j = i + 1;j <= n;++j){
            s += a[j];
            if (pre[i] < s) continue;

            int p = lower_bound(pre,pre + i,pre[i] - s) - pre;
            if (pre[i] - pre[p] == s){
                ans = max(ans,j - p);
            }
        }
    }
    cout << ans;
}
