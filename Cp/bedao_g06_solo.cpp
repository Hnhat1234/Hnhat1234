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

ll a[105];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int t; cin >> t;
    while (t--){
        int n,k,p; cin >> n >> k >> p;

        for (int i = 1;i <= n;++i){
            cin >> a[i];
        }
        if (k % 2 == 1){
            cout << (p == 0 ? *max_element(a + 1,a + 1 + n) : *min_element(a + 1,a + 1 + n));
        }else{
            ll tmax = a[2]; ll tmi = a[2];

            tmax = max(tmax,a[n - 1]); tmi = min(tmi,a[n - 1]);
            for (int i = 2;i < n;++i){
                tmax = max(tmax,min(a[i - 1],a[i + 1]));
                tmi = min(tmi,max(a[i - 1],a[i + 1]));
            }

            cout << (p == 0 ? tmax : tmi);
        }

        cout << '\n';
    }
}
