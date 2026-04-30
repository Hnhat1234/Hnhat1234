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

ll a[1000005], b[1000005];

ll pre[1000005]; ll pos[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);
    int n; cin >> n;
    ll x,y; cin >> x >> y;
    for (int i = 1;i <= n;++i){cin >> a[i]; pre[i] = pre[i - 1] + a[i];}

    ll ans = -1e18; ll l,r;

    ll min_pos = 0;

    for (int i = 1;i <= n;++i){
        if (a[i] < x){pos[i] = i; min_pos = 0;}
        else{
            if (a[i] > y && min_pos != 0){
                if (ans < pre[i] - pre[min_pos] + b[min_pos]){
                    ans = pre[i] - pre[min_pos] + b[min_pos];
                    l = pos[min_pos - 1] + 1;
                    r = i;
                }
            }else if (a[i] <= y){
                if (ans < pre[i] - pre[pos[i - 1]]){
                    ans = pre[i] - pre[pos[i - 1]];
                    l = pos[i - 1] + 1; r = i;
                }
                min_pos = i;
            }
            b[i] = pre[i] - pre[pos[i - 1]];
            if (pre[pos[i - 1]] > pre[i]){pos[i] = i;}
            else{pos[i] = pos[i - 1];}
        }
    }
    cout << ans << '\n';
    cout << l << ' ' << r;
}
