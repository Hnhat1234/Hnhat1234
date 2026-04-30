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

ll a[100005], b[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int n,x; cin >> n >> x;
        for (int i = 1;i <= n;++i){cin >> a[i]; b[i] = a[i];}
        sort(b + 1,b + 1 + n);
        int check = 1;
        for (int i = 2;i <= n;++i){
            if (a[i] < a[i - 1]){check = 0; break;}
        }
        if (check){cout << "YES" << '\n';}
        else{
            if (x == n){cout << "NO" << '\n';}
            else{
              int check = 1;
              for (int i = 1;i <= n;++i){
                 if (i - x <= 0 && i + x > n){
                    if (a[i] != b[i]){check = 0; break;}
                 }
              }
              cout << (check ? "YES" : "NO") << '\n';
            }
        }
    }
}
