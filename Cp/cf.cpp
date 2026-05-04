#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[200005], m;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n >> m;
        map<ll, int> cnt;
        for (int i = 1;i <= n;++i){cin >> a[i];}
        for (int i = 1;i <= n;++i){ll c; cin >> c; cnt[a[i]] = c;}
        ll ans = 0;
        for (int i = 1;i <= n;++i){
            ll x = a[i];
            ll y = x + 1;
            ll cnt_x = cnt[x]; ll cnt_y = cnt[y];
            ans = max(ans, min(m / x, cnt_x) * x);
            ans = max(ans, min(m / y, cnt_y) * y);
            if (cnt_y){
                ll lim = m / x;
                ll remain = m - min(lim, cnt_x) * x;
                ll k = remain / y;

                ll cur_max = min(cnt_x, lim) * x + min(k, cnt_y) * y;
                ans = max(ans, cur_max + min(min(lim, cnt_x), min(cnt_y - min(cnt_y, k), m - cur_max)));
            }
        }
        cout << ans << '\n';
    }
}
