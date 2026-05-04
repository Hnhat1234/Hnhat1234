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

ll a[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    int n; cin >> n;
    for (int i = 1;i <= n;++i) cin >> a[i];

    int l = 1; int r = n;

    int s1 = a[1]; int s2 = a[n];

    int ans = 0;
    while (l < r){
        if (s1 == s2){l++; r--; s1 = a[l]; s2 = a[r];}
        else{
            if (s1 < s2){s1 += a[++l]; ans++;}
            else if (s1 > s2){s2 += a[--r]; ans++;}
        }
    }
    cout << ans;
}
