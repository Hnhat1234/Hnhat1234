#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n,a[1000005];

ll pre[1000005];ll suf[1000005];

ll bit[1000005][2];

void update1(int u,int t){
    while (u > 0){
        bit[u][t]+=1;
        u-=(u&(-u));
    }
}
int get1(int u,int t){
    int s=0;
    while (u <= n){
        s+=bit[u][t];
        u+=(u&(-u));
    }
    return s;
}
void update2(int u,int t){
    while (u <= n){
        bit[u][t]+=1;
        u+=(u&(-u));
    }
}
int get2(int u,int t){
    int s=0;
    while (u > 0){
        s+=bit[u][t];
        u-=(u&(-u));
    }
    return s;
}
int main(){
    vector<pair<int,int>> v;
    cin >> n;
    for (int i=1;i<=n;++i){cin >> a[i];v.push_back({a[i],i});}
    int m=v.size();
    sort(v.begin(),v.end());
    for (int i=0;i<m;++i){
        pre[i+1]=pre[i]+get1(v[i].second,0);
        update1(v[i].second,0);
    }
    for (int i=m-1;i >= 0;--i){
        suf[i+1]=suf[i+2]+get2(v[i].second,1);
        update2(v[i].second,1);
    }
    ll ans=1e18;
    if (n==1){cout << 0;return 0;}
    for (int i=0;i<=n;++i){
        ans=min(ans,pre[i-1]+suf[i+1]);
    }
    cout << ans;
}
