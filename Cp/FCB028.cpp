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

ll cnt[40][2];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        memset(cnt,0,sizeof cnt);
        int n; cin >> n;

        ll ans = 0;
        for (int i = 1;i <= n;++i){
            cin >> a[i];
            int dem = 0;

            while (a[i] != 0){
                int x = a[i] % 2;
                if (x == 1){ans += cnt[dem][0] * (ll)pow(2,dem); cnt[dem][1]++;}
                else{
                    ans += cnt[dem][1] * (ll)pow(2,dem);
                    cnt[dem][0]++;
                }
                dem += 1;
                a[i] /= 2;
            }
            for (int i = dem;i <= 31;++i){ans += cnt[i][1] * (ll)pow(2,i); cnt[i][0]++;}
        }
        cout << ans << '\n';
    }
}
