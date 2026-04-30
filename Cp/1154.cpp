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

int a[200005], p[200005];

int ans[200005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,k; cin >> n >> k;
    set<int> s1; set<int> s2;
    for (int i = 1;i <= n;++i){cin >> a[i]; p[a[i]] = i; s1.insert(a[i]); s2.insert(a[i]);}

    int t = 1;
    while (1){
         if (s1.size() == 0){break;}
         auto x = s1.end(); x--;
         int pos = p[*x]; s1.erase(x); s2.erase(pos);
         ans[pos] = t;
         for (int i = 1;i <= k;++i){
            auto p1 = s2.lower_bound(pos);
            if (p1 == s2.begin()){break;}
            p1--; ans[*p1] = t; s1.erase(a[*p1]); s2.erase(p1);
         }
         for (int i = 1;i <= k;++i){
            auto p2 = s2.upper_bound(pos);
            if (p2 == s2.end()){break;}
            ans[*p2] = t; s1.erase(a[*p2]); s2.erase(p2);
         }
         t = (t == 1 ? 2 : 1);
    }
    for (int i = 1;i <= n;++i){cout << ans[i];}
    return 0;
}
