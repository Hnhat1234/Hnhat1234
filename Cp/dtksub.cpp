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

const ll base = 31;
const ll mod = 1000000003;

ll p[50005], pw[50005], hasht[50005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int n,k; cin >> n >> k;

    string s; cin >> s;

    s = ' ' + s;

    pw[0] = 1;
    for (int i = 1;i <= n;++i) pw[i] = (pw[i - 1] * base) % mod;

    for (int i = 1;i <= n;++i) p[i] = (p[i - 1] * base + s[i] - 'a' + 1) % mod;

    int l = 1; int r = n;

    int ans = 0;
    while (l <= r){
        int m = (l + r)/2;
        for (int i = 1;i <= n - m + 1;++i){
            hasht[i] = (p[i + m - 1] - p[i - 1] * pw[m] + mod * mod) % mod;
        }
        sort(hasht + 1,hasht + (n - m + 1) + 1);

        int temp = 1;
        for (int i = 2;i <= n - m + 1;++i){
            if (temp >= k) break;

            temp = (hasht[i] == hasht[i - 1] ? (temp + 1) : 1);
        }

        if (temp >= k){ans = max(ans,m); l = (m + 1);}
        else{
            r = m - 1;
        }
    }

    cout << ans;

}
