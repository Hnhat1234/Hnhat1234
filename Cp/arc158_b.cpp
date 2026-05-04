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

ll a[200005];

double tinh(ll a,ll b,ll c){
    double res = (a + b + c) * 1.00 / (a * b * c);
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    for (int i = 1;i <= n;++i){cin >> a[i];}
    sort(a + 1,a + 1 + n);
    double mi = (a[1] + a[2] + a[3]) * 1.00 / (a[1] * a[2] * a[3]);
    double ma = (a[1] + a[2] + a[3]) * 1.00 / (a[1] * a[2] * a[3]);

    int i1 = 0; int i2 = 0;
    for (int i = 1;i <= n;++i){
        if (a[i] < 0){i1 = i;}
        else{
            if (i2 == 0){i2 = i;}
        }
    }
    for (int i = 1;i < n;++i){
        if (a[i] * a[i + 1] * a[i1] != 0 && i != i1 && (i + 1) != i1){
            mi = min(mi,tinh(a[i],a[i + 1],a[i1]));
            ma = max(ma,tinh(a[i],a[i + 1],a[i1]));
        }
        if (a[i] * a[i + 1] * a[i2] != 0 && i != i2 && (i + 1) != i2){
            mi = min(mi,tinh(a[i],a[i + 1],a[i2]));
            ma = max(ma,tinh(a[i],a[i + 1],a[i2]));
        }
        if (i != 1){
            mi = min(mi,tinh(a[i],a[i + 1],a[1]));
            ma = max(ma,tinh(a[i],a[i + 1],a[1]));
        }
        if ((i + 1) != n){
            mi = min(mi,tinh(a[i],a[i + 1],a[n]));
            ma = max(ma,tinh(a[i],a[i + 1],a[n]));
        }
    }
    cout << fixed << setprecision(12) << mi;
    cout << '\n';
    cout << fixed << setprecision(12) << ma;
}
