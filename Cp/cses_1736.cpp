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

ll pre[200005];

ll t[200005];

ll st[800005];

pair<ll,ll> lazy[800005];

void fix(int id,int l,int r){
    st[id] += lazy[id].first * (r + l) * (r - l + 1)/2;
    st[id] += (r - l + 1) * lazy[id].second;
    if (l != r){
    lazy[id * 2].first += lazy[id].first;
    lazy[id * 2].second += lazy[id].second;
    lazy[id * 2 + 1].first += lazy[id].first;
    lazy[id * 2 + 1].second += lazy[id].second;
    }
    lazy[id] = {0,0};
}

void build(int id,int l,int r){
    if (l == r){st[id] = t[l]; return;}
    int mid = (l + r)/2;
    build(id * 2,l,mid);
    build(id * 2 + 1,mid + 1,r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}
void update(int id,int l,int r,int u,int v,int k){
    fix(id,l,r);
    if (l > v || r < u){return;}
    if (l >= u && r <= v){
        lazy[id].first = 1;
        lazy[id].second = k;
        fix(id,l,r);
        return;
    }
    int mid = (l + r)/2;
    update(id * 2,l,mid,u,v,k);
    update(id * 2 + 1,mid + 1,r,u,v,k);
    st[id] = st[id * 2] + st[id * 2 + 1];
}
ll get(int id,int l,int r,int u,int v){
    fix(id,l,r);
    if (l > v || r < u){return 0;}
    if (l >= u && r <= v){return st[id];}
    int mid = (l + r)/2;
    return get(id * 2,l,mid,u,v) + get(id * 2 + 1,mid + 1,r,u,v);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,q; cin >> n >> q;
    for (int i = 1;i <= n;++i){cin >> t[i]; pre[i] = pre[i - 1] + t[i];}
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int l,r; cin >> l >> r;
            update(1,1,n,l,r,1 - l);
        }else{
            int l,r; cin >> l >> r;
            cout << get(1,1,n,l,r) + pre[r] - pre[l - 1] << '\n';
        }
    }
}
