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

const int block = 720;

struct query{
    int l,r,idx;
};

bool cmp(query a,query b){
    if (a.l/block != b.l/block){
        return a.l/block < b.l/block;
    }
    return a.r < b.r;
}

query q[500005];

ll a[500005], b[500005];

int cnt[500005],ans[500005];

int check1(int n){
    if (n == 3){return -1;}
    if (n == 2){return 1;}
    return 0;
}
int check2(int n){
    if (n == 1){return -1;}
    if (n == 2){return 1;}
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,t; cin >> n >> t;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1,b + 1 + n);
    for (int i = 1;i <= n;++i){
        a[i] = lower_bound(b + 1,b + 1 + n,a[i]) - b;
    }

    for (int i = 1;i <= t;++i){
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
    }

    sort(q + 1,q + 1 + t,cmp);
    int cur = 0;
    for (int i = 1;i <= t;++i){
        int l = q[i].l; int r = q[i].r;
        while (l <= q[i - 1].l - 1){cnt[a[l]]++; cur += check1(cnt[a[l]]); l++;}
        while (l - 1 >= q[i - 1].l){cnt[a[l - 1]]--; cur += check2(cnt[a[l - 1]]); l--;}
        while (r + 1 <= q[i - 1].r){cnt[a[r + 1]]--; cur += check2(cnt[a[r + 1]]); r++;}
        while (r >= q[i - 1].r + 1){cnt[a[r]]++; cur += check1(cnt[a[r]]); r--;}
        ans[q[i].idx] = cur;
    }
    for (int i = 1;i <= t;++i){cout << ans[i] << ' ';}
}
