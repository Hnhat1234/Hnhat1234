#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct node{
    multiset<ll> s;
};

node sg[400005];

ll a[100005];

void build(int id,int l,int r){
    if (l==r){sg[id].s.insert(a[l]);return;}
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    for (ll x:sg[id*2].s){sg[id].s.insert(x);}
    for (ll x:sg[id*2+1].s){sg[id].s.insert(x);}
}
ll update(int id,int l,int r,int i,ll v){
    if (l > i || r < i){return 0LL;}
    if (l==r){
        ll val = *sg[id].s.begin();
        a[l] = v;
        sg[id].s.clear();
        sg[id].s.insert(v);
        return val;
    }
    int mid=(l+r)/2;
    ll x1 = update(id * 2,l,mid,i,v);
    ll x2 = update(id * 2 + 1,mid + 1,r,i,v);

    sg[id].s.insert(v);
    auto p1 = sg[id].s.find(x1);
    auto p2 = sg[id].s.find(x2);
    if (p1 != sg[id].s.end()){
        sg[id].s.erase(p1);
        return x1;
    }
    if (p2 != sg[id].s.end()){
        sg[id].s.erase(p2);
        return x2;
    }
    return 0LL;

}
ll get(int id,int l,int r,int u,int v,ll k){
    if (l > v || r < u){return 1e18;}
    if (l >= u &&r <= v){
        auto p=sg[id].s.lower_bound(k);
        if (p==sg[id].s.end()){return 1e18;}
        else{return *p;}
    }
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v,k),get(id*2+1,mid+1,r,u,v,k));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin >> n >> m;
    for (int i=1;i<=n;++i){cin >> a[i];}
    build(1,1,n);
    while (m--){
        int q;cin >> q;
        if (q==1){
            int i;
            ll v;
            cin >> i >> v;
            update(1,1,n,i,v);
        }else{
            int l,r;
            ll k;
            cin >> l >> r >> k;
            ll p=1e18;
            ll ans=get(1,1,n,l,r,k);
            cout << (ans==p?-1:ans) << '\n';
        }
    }
}
