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

int snt[1000005];

void sieve(){
    for (int i = 2;i <= 1000000;++i){snt[i] = 1;}
    for (int i = 2;i <= 1000;++i){
        if (!snt[i]){continue;}
        for (int j = i * i;j <= 1000000;j += i){
            snt[j] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    sieve();
    while (t--){
        ll n; cin >> n;

        ll a,b;
        for (int i = 2;i <= 1000000;++i){
            if (snt[i] && (n % i == 0)){
                if (n % (i * i) == 0){a = i; b = n/(i * i); break;}
                else{
                    a = sqrt(n/i); b = i; break;
                }
            }
        }
        cout << a << ' ' << b << '\n';
    }
}
