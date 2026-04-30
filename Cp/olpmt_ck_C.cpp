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

int n, k;

ll prema[200005]; ll sufma[200005];

ll b[200005];
void sub(){

    vector<ll> a(25);
    for (int i = 0;i < n;++i){
        cin >> a[i];
    }

    ll ans = -1e18;
    for (int s = 0;s < n;++s){
        for (int i = 0;i < n;++i){
            b[i] = a[(s + i) % n];
        }
        for (int i = 1;i <= n;++i){prema[i] = max(prema[i - 1],b[i - 1]);}
        for (int i = n;i >= 1;--i){sufma[i] = max(sufma[i + 1],b[i - 1]);}

        for (int i = 1;i < s - 1;++i){
            ans = max(ans,-b[i + 1] + prema[i] + sufma[i + 2]);
        }
    }

    cout << ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    cin >> n >> k;
    if (k == 1){sub();}
    else{

    }
}
