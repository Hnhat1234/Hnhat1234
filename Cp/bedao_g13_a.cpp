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

vector<int> prime[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    ll ans = 0;
    int n; cin >> n;
    for (int i = 2;i <= 1000000;++i){
        if (snt[i]){continue;}
        for (int j = i * 2;j <= 1000000;j += i){
            snt[j] = 1;
            prime[j].push_back(i);
        }
    }
    for (int i = 2;i <= n;++i){
        if (!snt[i]){prime[i].push_back(i);}
    }
    for (int i = 1;i < n;++i){
         ll x = 1; ll y = 1;

         int temp1 = i; int temp2 = n - i;
         for (int j:prime[i]){
             if (temp1 == 1){continue;}
             ll tot = 1;
             while (temp1 % j == 0){temp1/=j; tot += 1;}
             x *= tot;
         }
         for (int j:prime[n - i]){
             if (temp2 == 1){continue;}
             ll tot = 1;
             while (temp2 % j == 0){temp2/=j; tot += 1;}
             y *= tot;
         }
         ans += x * y;
    }
    cout << ans;
}
