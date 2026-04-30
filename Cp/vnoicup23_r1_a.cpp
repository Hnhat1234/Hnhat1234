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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int tm,sm,ty,sy;
        cin >> tm >> sm >> ty >> sy;

        int x1 = 0; int y1 = 0;
        int x2 = 0; int y2 = 0;

        if (90 * sm >= 10 * tm){x1 = 90; y1 = tm;}
        else{
            x1 = 100;
            y1 = tm + sm;
        }

        if (90 * sy >= 10 * ty){x2 = 90; y2 = ty;}
        else{
            x2 = 100;
            y2 = ty + sy;
        }

        if (x1 * y2 < x2 * y1){cout << "Megumin";}
        else if (x1 * y2 > x2 * y1){cout << "Yunyun";}
        else{cout << "Draw";}
        cout << '\n';
    }
}
