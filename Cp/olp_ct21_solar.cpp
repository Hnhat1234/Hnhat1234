#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct node{
    ll minpos,sum;
};

node st[4000005];

ll a[1000005];

ll getans(int id,int l,int r,int u,int v){
    if (l > v || r < u){return 0LL;}
    if (l >= u && r <= v){return st[id].sum;}
    int mid=(l+r)/2;
    return getans(id*2,l,mid,u,v)+getans(id*2+1,mid+1,r,u,v);
}
int getmin(int id,int l,int r,int u,int v){
    if (l > v || r < u){return 0;}
    if (l >= u && r <= v){return st[id].minpos;}
    int mid=(l+r)/2;
    int p1=getmin(id*2,l,mid,u,v);
    int p2=getmin(id*2+1,mid+1,r,u,v);
    if (a[p1] <= a[p2]){return p1;}
    else{
        return p2;
    }
}
void update(int id,int l,int r,int pos,int p){
    if (l > pos || r < pos){return;}
    if (l==r){
        a[l]=p;
        st[id]={l,a[l]};
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,p);
    update(id*2+1,mid+1,r,pos,p);
    st[id].sum=st[id*2].sum+st[id*2+1].sum;
    if (a[st[id*2].minpos] <= a[st[id*2+1].minpos]){st[id].minpos=st[id*2].minpos;}
    else{st[id].minpos=st[id*2+1].minpos;}
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        update(1,1,n,i,a[i]);
    }
    a[0]=1e9;
    ll inc=0;
    while (q--){
        int ques;cin >> ques;
        if (ques==1){
            ll d;cin >> d;
            inc+=d;
            if (inc > n){inc%=n;}
        }else if (ques==2){
            int s,t,p;cin >> s >> t >> p;
            s-=inc;
            t-=inc;
            if (s<=0){s+=n;}
            if (t<=0){t+=n;}
            if (s <= t){
                int p1=getmin(1,1,n,s,t);
                update(1,1,n,p1,p);
            }
            else{
                int p1=getmin(1,1,n,s,n);
                int p2=getmin(1,1,n,1,t);
                if (a[p1] <= a[p2]){update(1,1,n,p1,p);}
                else{update(1,1,n,p2,p);}
            }
        }else{
            int s,t;cin >> s >> t;
            s-=inc;
            t-=inc;
            if (s<=0){s+=n;}
            if (t<=0){t+=n;}
            if (s <= t){cout << getans(1,1,n,s,t) << '\n';}
            else{
                cout << getans(1,1,n,s,n)+getans(1,1,n,1,t) << '\n';
            }
        }
    }
}
