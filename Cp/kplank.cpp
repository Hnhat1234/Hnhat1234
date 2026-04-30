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

ll a[1000005], l[1000005], r[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    for (int i = 1;i <= n;++i){cin >> a[i];}
    stack<int> s1;
    for (int i = 1;i <= n;++i){
        while (s1.size() && a[s1.top()] >= a[i]){s1.pop();}
        if (s1.empty()){
            l[i] = 1;
            s1.push(i);
        }else{
            l[i] = s1.top() + 1;
            s1.push(i);
        }
    }
    stack<int> s2;
    for (int i = n;i >= 1;--i){
        while (s2.size() && a[s2.top()] >= a[i]){s2.pop();}
        if (s2.empty()){
            r[i] = n;
            s2.push(i);
        }else{
            r[i] = s2.top() - 1;
            s2.push(i);
        }
    }

    ll ans = 0;
    for (int i = 1;i <= n;++i){
        if (r[i] - l[i] + 1 < a[i]) continue;
        ans = max(ans,a[i]);
    }
    cout << ans;
}
