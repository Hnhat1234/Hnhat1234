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
    int n; cin >> n;
    if (n == 4){
        cout << 0 << ' ' << 0 << '\n';
        cout << 3 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 0 << '\n';
        cout << 0 << ' ' << 3 << '\n';
        cout << 0 << ' ' << 0 << ' ' << 3 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 0 << ' ' << 0 << ' ' << 3 << '\n';
    }else{
        for (int i = 1;i <= n - 2 - (n % 2 == 0);++i){
            cout << i << ' ' << i << '\n';
        }
        for (int i = 0;i <= 1;++i){
            if (i == 1 && (n % 2 != 0)){
                cout << (n - 2) << ' ' << 0 << '\n';
                break;
            }
            cout << i << ' ' << n - 2 - (n % 2 == 0) - i << '\n';
        }
        if (n % 2 == 0){cout << (n - 2 - (n % 2 == 0)) << ' ' << 0 << '\n';}
        cout << 1 << ' ' << 1 << ' ' << n - 2 - (n % 2 == 0) << ' ' << n - 2 - (n % 2 == 0) << '\n';

        if (n % 2 == 0){
        cout << 0 << ' ' << n - 2 - (n % 2 == 0) << ' ' << (n - 2 - (n % 2 == 0)) << ' ' << 0 << '\n';
        }else{
            cout << 0 << ' ' << n - 2 << ' ' << n - 2 << ' ' << 0 << '\n';
        }
    }
}
