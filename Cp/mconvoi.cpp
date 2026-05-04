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

ll mod = 1e9 + 7;

struct node{
    ll x,y;
};
struct node1{
    ll val;
    ll cnt;
};

node a[300005];

node1 f[300005], bit[300005];

ll b[300005];

bool cmp(node a,node b){
    return (a.x < b.x || (a.x == b.x && a.y > b.y));
}
void update(int i,int n,node1 res){
    while (i <= n){
        if (bit[i].val < res.val){
            bit[i] = res;
        }else if (bit[i].val == res.val){
            bit[i].cnt = (bit[i].cnt + res.cnt) % mod;
        }
        i += (i & (-i));
    }
}
node1 get(int i){
    node1 res = {0,1};
    while (i > 0){
        if (res.val < bit[i].val){res.val = bit[i].val; res.cnt = bit[i].cnt;}
        else if (res.val == bit[i].val){
            res.cnt = (res.cnt + bit[i].cnt) % mod;
        }
        i -= (i & (-i));
    }
    res.val++;
    return res;
}
int main(){
    int n; cin >> n;
    for (int i = 1;i <= n;++i){
        cin >> a[i].x >> a[i].y;
        b[i] = a[i].y;
    }
    sort(a + 1,a + 1 + n,cmp);
    sort(b + 1,b + 1 + n);
    for (int i = 1;i <= n;++i){
        int p = lower_bound(b + 1,b + 1 + n,a[i].y) - b;
        f[i] = get(p - 1);
        update(p,n,f[i]);
    }
    node1 ans = {0,0};
    for (int i = 1;i <= n;++i){
        if (ans.val < f[i].val){ans = f[i];}
        else if (ans.val == f[i].val){
            ans.cnt = (ans.cnt + f[i].cnt) % mod;
        }
    }
    cout << ans.val << '\n' << ans.cnt;
}
