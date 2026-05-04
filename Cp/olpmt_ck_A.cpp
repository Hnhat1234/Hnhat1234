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

ll a[3][3];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    map<ll,ll> sum; map<ll,ll> dif;
    for (int i = 0;i <= 2;++i){
        for (int j = 0;j <= 2;++j){
            cin >> a[i][j];
            dif[a[i][j]]++;
        }
    }

    for (int i = 0;i <= 2;++i){
        ll s1 = 0; ll s2 = 0;
        for (int j = 0;j <= 2;++j){
            s1 += a[i][j];
            s2 += a[j][i];
        }
        sum[s1] = 1; sum[s2] = 1;
    }

    if (sum.size() == 1 && dif.size() >= 2){cout << "YES";}
    else cout << "NO";
}
