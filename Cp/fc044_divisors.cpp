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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int n,k;
    while (cin >> n){
        map<int,int> m; map<int,int> m1;
        cin >> k;

        for (int i = k + 1;i <= n;++i){
            int x = i; int t = sqrt(x);
            for (int j = 2;j <= t;++j){
                while (x % j == 0){
                    x/=j;
                    m[j]++;
                }
            }
            if (x != 1){m[x]++;}
        }

        for (int i = 2;i <= n - k;++i){
            int x = i; int t = sqrt(x);
            for (int j = 2;j <= t;++j){
                while (x % j == 0){
                    x/=j;
                    m1[j]++;
                }
            }
            if (x != 1){m1[x]++;}
        }

        ll ans = 1;
        for (auto x : m){
            ans *= (m[x.first] - m1[x.first] + 1);
        }

        cout << ans << '\n';
    }
}
