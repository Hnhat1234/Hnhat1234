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

ll sufma[500005];

ll a[500005], b[500005];

pair<ll,ll> p[500005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        sufma[n + 1] = -1e9;
        for (int i = 1;i <= n;++i){
            cin >> p[i].first >> p[i].second;
        }
        multiset<ll> s;
        sort(p + 1,p + 1 + n);
        for (int i = n;i >= 1;--i){
            a[i] = p[i].first;
            b[i] = p[i].second;
            s.insert(p[i].second);
            sufma[i] = max(p[i].second,sufma[i + 1]);
        }
        ll ans = 1e9;
        a[n + 1] = a[n];
        for (int i = n;i >= 1;--i){
            if (a[i] != a[i + 1]){
                int j = i + 1;
                while (j < n && a[j] == a[j + 1]){
                    s.erase(s.lower_bound(b[j]));
                    j++;
                }
                if (j <= n){s.erase(s.lower_bound(b[j]));}
            }
            s.erase(s.lower_bound(b[i]));
            int x = upper_bound(a + 1,a + 1 + n,a[i]) - a;
            ll val = max(sufma[x],a[i]);
            auto pos = s.lower_bound(val);
            if (pos != s.end()){
                ans = min(ans,abs(a[i] - max(*pos,sufma[x])));
            }
            if (pos == s.begin()){ans = min(ans,abs(a[i] - sufma[x]));}
            else{
                pos--;
                ans = min(ans,abs(a[i] - max(*pos,sufma[x])));
            }
            s.insert(b[i]);
        }
        cout << ans << '\n';
    }
}
