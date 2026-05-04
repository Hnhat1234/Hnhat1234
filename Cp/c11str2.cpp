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

ll pw[100005], hasht[100005];

ll get(int l,int r){
    return (hasht[r] - hasht[l - 1] * pw[r - l + 1] + modhash * modhash) % modhash;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    string a,b; cin >> a >> b;
    int n = a.size();
    a = ' ' + a; b = ' ' + b;
    pw[0] = 1;
    for (int i = 1;i <= n;++i){pw[i] = (pw[i - 1] * basehash) % modhash;}
    for (int i = 1;i <= n;++i){hasht[i] = (hasht[i - 1] * basehash + a[i] - 'a' + 1) % modhash;}

    ll temp = 0; ll r = 0;
    for (int i = 1;i < b.size();++i){
        temp = (temp * basehash + b[i] - 'a' + 1) % modhash;
        if (n - i + 1 < 0){break;}
        if (temp == get(n - i + 1,n)){r = i;}
    }
    for (int i = 1;i <= n;++i){cout << a[i];}
    for (int i = r + 1;i < b.size();++i){cout << b[i];}

}
