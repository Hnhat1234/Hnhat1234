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

int x[105];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int n,a,b;cin >> n >> a >> b;
        for (int i = 1;i <= n;++i){
            cin >> x[i];
        }

        int check = 0;

        x[n + 1] = x[n];
        for (int i = 1;i <= n;++i){
            int l = x[i] - x[1] + 1;
            int r = x[n] - x[i + 1] + 1;
            if (l <= a + 1 && r <= b + 1){check = 1; break;}
            if (l <= b + 1 && r <= a + 1){check = 1; break;}
        }
        cout << (check ? "YES" : "NO") << '\n';
    }
}
