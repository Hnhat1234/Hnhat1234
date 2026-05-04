#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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

#define ii pair<double, double>

using namespace std;

const ll basehash = 31;
const ll modhash = 1000000003;

ii p[50005];

double dientich(ii a,ii b,ii c){
    return fabs((b.first - a.first)*(c.second - a.second)-(c.first - a.first)*(b.second - a.second));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (1){
        int n; cin >> n;
        if (n == -1){break;}
        for (int i = 1;i <= n;++i){
            cin >> p[i].first >> p[i].second;
        }
        double res = 0;
        for (int i = 1;i <= n;++i){
            int k = i + 1;
            for (int j = i + 1;j <= n;++j){
                k = max(k,j + 1);
                while (k + 1 <= n && dientich(p[i],p[j],p[k]) <= dientich(p[i],p[j],p[k + 1])){k++;}
                if (k <= n){res = max(res,dientich(p[i],p[j],p[k]));}
            }
        }
        cout << fixed << setprecision(2) << res * 0.5 << '\n';
    }
}
