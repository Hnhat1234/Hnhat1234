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

ll p[20];

ll a[200005];

vector<ll> b[20];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    p[0] = 1;
    for (int i = 1;i <= 20;++i){p[i] = p[i - 1] * 10;}

    ll ans = 0;
    for (int i = 1;i <= n;++i){
        cin >> a[i];

        int dem = 1; ll cur = 0;
        ll temp = a[i];
        while (dem <= 15){
            ans += (temp % 10);
            cur += (temp % 10) * p[dem - 1];
            b[dem].push_back(cur);
            dem += 1;
            temp/=10;
        }
    }

    ans = 2 * n * ans;
    for (int k = 1;k <= 15;++k){
        sort(b[k].begin(),b[k].end());
    }
    for (int i = 1;i <= n;++i){
        ll temp = a[i]; ll cur = 0;
        int dem = 1;
        while(dem <= 15){
            cur += (temp % 10) * p[dem - 1];
            int p1 = lower_bound(b[dem].begin(),b[dem].end(),p[dem] - cur) - b[dem].begin();
            ans = (ans - (b[dem].size() - p1) * 9LL);
            dem += 1;
            temp/=10;
        }
    }
    cout << ans;
}
