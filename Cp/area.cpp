#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct dat{
    int x,l,r,t;
};
struct node{
    int d,l;
};

node st[8*30005];

dat a[20005];

bool cmp(dat a,dat b){
    return (a.x < b.x||((a.x==b.x)&&(a.t < b.t)));
}
void update(int id,int l,int r,int u,int v,int type){
    if (l > v || r < u){return;}
    if (l>=u&&r<=v){
        st[id].d+=type;
        if (type==1){st[id].l=r-l+1;}
        if (st[id].d==0){st[id].l=st[id*2].l+st[id*2+1].l;}
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,type);
    update(id*2+1,mid+1,r,u,v,type);
    if (st[id].d==0){st[id].l=st[id*2].l+st[id*2+1].l;}
}
int main(){
     ios_base::sync_with_stdio(false);cin.tie(0);
     int n;cin >> n;

     int m=0;
     for (int i=1;i<=n;++i){
         int x1,y1,x2,y2;
         cin >> x1 >> y1 >> x2 >> y2;
         a[++m]={x1,y1+1,y2,1};
         a[++m]={x2,y1+1,y2,-1};
     }
     sort(a+1,a+1+m,cmp);
     ll ans=0;
     for (int i=1;i<=m;++i){
         ans+=st[1].l*(a[i].x-a[i-1].x);
         update(1,1,30000,a[i].l,a[i].r,a[i].t);
     }
     cout << ans;
}
