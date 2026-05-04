#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod=1e9+7;

ll st[400005];

vector<pair<int,int>> lazy(400005);

void laz(int id,int l,int r){
    ll a=lazy[id].first;
    ll b=lazy[id].second;
    st[id]+=(a*(r+l)*(r-l+1)/2)%mod;
    st[id]%=mod;
    st[id]+=(b*(r-l+1))%mod;
    st[id]%=mod;
    if (l != r){
        lazy[id*2].first=(lazy[id*2].first+a)%mod;
        lazy[id*2].second=(lazy[id*2].second+b)%mod;
        lazy[id*2+1].first=(lazy[id*2+1].first+a)%mod;
        lazy[id*2+1].second=(lazy[id*2+1].second+b)%mod;
    }
    lazy[id]={0,0};
}

void update(int id,int l,int r,int u,int v,ll a,ll b){
    laz(id,l,r);
    if (l > v || r < u){return;}
    if (l >= u && r <= v){
        lazy[id].first=a;
        lazy[id].second=(b-1LL*u*a+2*mod*mod)%mod;
        laz(id,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,a,b);
    update(id*2+1,mid+1,r,u,v,a,b);
    st[id]=(st[id*2]+st[id*2+1])%mod;
}
ll get(int id,int l,int r,int u,int v){
    laz(id,l,r);
    if (l > v || r < u){return 0;}
    if (l >= u && r <= v){return st[id];}
    int mid=(l+r)/2;
    return (get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v))%mod;
}
int main(){
    int n,m;cin >> n >> m;
    for (int i=0;i<m;++i){
        int q;cin >> q;
        if (q==1){
            int l,r;ll a,b;
            cin >> l >> r >> a >> b;
            update(1,1,n,l,r,a,b);
        }else{
            int l,r;cin >> l >> r;
            cout << get(1,1,n,l,r) << '\n';
        }
    }
}
