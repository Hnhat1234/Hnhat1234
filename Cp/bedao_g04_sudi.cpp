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

ll lmin[100005],rmin[100005];

ll lmax[100005],rmax[100005];

ll a[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    int n; cin >> n;
    for (int i = 1;i <= n;++i) cin >> a[i];

    stack<int> q1,q2;

    for (int i = 1;i <= n;++i){
        while (!q1.empty() && a[q1.top()] <= a[i]){
            q1.pop();
        }
        if (q1.empty()){
            lmax[i] = 1; q1.push(i);
        }else{
            lmax[i] = q1.top() + 1;
            q1.push(i);
        }

        while (!q2.empty() && a[q2.top()] >= a[i]){
            q2.pop();
        }
        if (q2.empty()){
            lmin[i] = 1; q2.push(i);
        }else{
            lmin[i] = q2.top() + 1; q2.push(i);
        }
    }
    while (q1.size()) q1.pop();
    while (q2.size()) q2.pop();
    for (int i = n;i >= 1;--i){
        while (!q1.empty() && a[q1.top()] <= a[i]){
            q1.pop();
        }
        if (q1.empty()){
            rmax[i] = n; q1.push(i);
        }else{
            rmax[i] = q1.top() - 1;
            q1.push(i);
        }

        while (!q2.empty() && a[q2.top()] >= a[i]){
            q2.pop();
        }
        if (q2.empty()){
            rmin[i] = n; q2.push(i);
        }else{
            rmin[i] = q2.top() - 1; q2.push(i);
        }
    }

    ll ans = 0;
    map<ll,ll> m;
    for (int i = 1;i <= n;++i){
        ans += a[i] * (rmax[i] - i + 1) * (i - max(lmax[i],m[a[i]] + 1) + 1);
        ans -= a[i] * (rmin[i] - i + 1) * (i - max(lmin[i],m[a[i]] + 1) + 1);

        m[a[i]] = i;
    }

    cout << ans;
}
