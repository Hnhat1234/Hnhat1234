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

ll a[100005], b[100005], f[100005], g[100005];

int bit[100005], bit1[100005];

void update(int i,int v){
    while (i > 0){
        bit[i] = max(bit[i],v);
        i -= (i & (-i));
    }
}
ll get(int i,int n){
    ll res = 0;
    while (i <= n){
        res = max(res,1LL * bit[i]);
        i += (i & (-i));
    }
    return res;
}

void update1(int i,int n,int v){
    while (i <= n){
        bit1[i] = max(bit1[i],v);
        i += (i & (-i));
    }
}
ll get1(int i){
    ll res = 0;
    while (i > 0){
        res = max(res,1LL * bit1[i]);
        i -= (i & (-i));
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    for (int i = 1;i <= n;++i){cin >> a[i]; b[i] = a[i];}
    sort(b + 1,b + 1 + n);

    for (int i = n;i >= 1;--i){
        int pos = lower_bound(b + 1,b + 1 + n,a[i]) - b;
        if (i == n){
            f[i] = 1;
            update(pos,f[i]);
        }else{
            f[i] = get(pos + 1,n) + 1;
            update(pos,f[i]);
        }
    }
    for (int i = n;i >= 1;--i){
        int pos = lower_bound(b + 1,b + 1 + n,a[i]) - b;
        if (i == n){
            g[i] = 1;
            update1(pos,n,g[i]);
        }else{
            g[i] = get1(pos - 1) + 1;
            update1(pos,n,g[i]);
        }
    }
    ll ans = 0;
    for (int i = 1;i <= n;++i){
        ans = max(ans,f[i] + g[i] - 1);
    }
    cout << ans;
}
