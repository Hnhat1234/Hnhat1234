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

int a[1000005], f[1000005];

ii p[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int k,n; cin >> n >> k;

    for (int i = 1;i <= n;++i){
        int x,y; cin >> x >> y;
        p[i] = {y,x};
        a[i] = y;
    }
    sort(p + 1,p + 1 + n);
    sort(a + 1,a + 1 + n);
    multiset<int> s; s.insert(0);
    for (int i = n;i >= 1;--i){
        s.insert(p[i].second);
        if (s.size() < (k + 1)) continue;
        else if (s.size() == (k + 1)){
            auto pos = s.begin();
            f[i] = abs((*pos) - *(++pos));
        }else{
            s.erase(s.begin());
            auto pos = s.begin();
            f[i] = abs((*pos) - *(++pos));
        }
    }
    ll ans = 0;
    for (int i = 1;i <= 1000000;++i){
        int pos = lower_bound(a + 1,a + 1 + n,i) - a;
        if (n - pos + 1 < k) break;
        ans += f[pos];
    }
    cout << ans;
}
