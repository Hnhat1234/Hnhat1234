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

int a[200005], k, n;

int cal(int l,int r){
    return (l - 1)/(k - 1) + (((l - 1) % (k - 1)) != 0) + (n - r)/(k - 1) + (((n - r) % (k - 1)) != 0);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    cin >> n >> k;

    int p = 0;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        if (a[i] == 1){p = i;}
    }

    int ans = 1e9;
    int l = 1; int r = k;
    while (r <= n){
        if (l <= p && r >= p){
            ans = min(ans,cal(l,r) + 1);
        }
        l++; r++;
    }

    cout << ans;
}
