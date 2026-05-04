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

int a[505][505];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m; cin >> n >> m;
    for (int i = 1;i <= n;++i){
        string s; cin >> s;
        for (int j = 1;j <= m;++j){
            a[i][j] = s[j - 1];
        }
    }
    for (int i = 1;i <= n - 1;++i){
        for (int j = 1;j <= m - 1;++j){
            if (a[i][j] != a[i + 1][j] && a[i][j] != a[i][j + 1] && a[i + 1][j] != a[i + 1][j + 1] && a[i][j + 1] == a[i + 1][j + 1]){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}
