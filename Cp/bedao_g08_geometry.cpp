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
    int t; cin >> t;

    long double sopi = 3.141592653589793238462643383279;
    while (t--){
        ll r1,r2; cin >> r1 >> r2;

        long double a = r1; long double b = r1 + r2;

        long double alpha = atan(a/b) * 180.0/sopi;
        long double beta = atan(b/a);

        long double s = (a * b)/2;
        long double s1 = sin(beta) * cos(beta) * r1 * r1;
        long double s2 = sopi * r1 * r1 * ((90.0 - 2 * alpha)/360.0);
        long double s3 = sopi * r2 * r2 * (alpha/360.0);

        cout << fixed << setprecision(4) << s - (s1 + s2 + s3) << '\n';
    }
}
