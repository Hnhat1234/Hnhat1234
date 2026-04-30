#include<bits/stdc++.h>
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 200005
#define pii pair<int,int>
#define fi first
#define se second
#define MOD 1000000007
using namespace std;
int n, a[maxn];
void operator += (pii &a, pii b)
{
    if (a.fi == b.fi) (a.se += b.se) %= MOD;
    else if (a.fi < b.fi) a = b;
}
struct Fenwick
{
    vector <pii> t;
    Fenwick(int n){
        t.resize(n+5);
    }
    pii getHigh(int x)
    {
        pii ans = {0, 1};
        for (;x<=n; x+=x&-x) ans += t[x];
        return ans;
    }
    void upLow(int x, pii val)
    {
        for (;x; x-=x&-x) t[x] += val;
    }

    pii getLow(int x)
    {
        pii ans = {0, 1};
        for (;x; x-=x&-x) ans += t[x];
        return ans;
    }
    void upHigh(int x, pii val)
    {
        for (;x<=n; x+=x&-x) t[x] += val;
    }
};
int p[maxn];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    vector <int> v;
    p[0] = 1;
    f1 (i, n) cin >> a[i], v.push_back(a[i]), p[i] = p[i-1] * 2 % MOD;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(a+1, a+n+1);
    Fenwick BIT_inc(n), BIT_dec(n);
    pii ans = {0, 1};
    f1 (i, n)
    {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        pii x = BIT_inc.getLow(a[i] - 1);
        pii y = BIT_dec.getHigh(a[i] + 1);
        ++x.fi; ++y.fi;
        pii cur = {x.fi + y.fi - 1, 1ll * x.se * y.se % MOD};
        ans += cur;
        BIT_inc.upHigh(a[i], x);
        BIT_dec.upLow(a[i], y);
    }
    cout << ans.fi << ' ' << 1ll * ans.se * p[n - ans.fi] % MOD;
}
