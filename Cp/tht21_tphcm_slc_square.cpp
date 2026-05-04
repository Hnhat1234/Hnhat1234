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

bool check(ll x){
    ll a = sqrt(x);
    return a * a == x;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    ll a,b,c; cin >> a >> b >> c;

    ll x = 1;
    for (int i = 2;i <= 1000000;++i){
        ll temp1 = 1; ll temp2 = 1; ll temp3 = 1;
        while (a % i == 0){a/=i; temp1 *= i;}
        while (b % i == 0){b/=i; temp2 *= i;}
        while (c % i == 0){c/=i; temp3 *= i;}

        ll temp = max(temp1,max(temp2,temp3));
        if (temp == 1) continue;
        else{
            ll tich = i;
            while (tich * tich < temp){
                tich *= i;
            }

            x *= tich;
        }
    }

    cout << x;
}
