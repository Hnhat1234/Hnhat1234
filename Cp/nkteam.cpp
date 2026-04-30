#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<pair<ll,pair<ll,ll>>> arr(100005);

ll bit[100005];

void update(int u,ll a){
    while (u <= 100000){
        bit[u]=min(bit[u],a);
        u+=(u&(-u));
    }
}
ll get(int u){
    ll ans=1e9;
    while (u > 0){
        ans=min(ans,bit[u]);
        u-=(u&(-u));
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin >> n;
    for (int i=1;i<=n;++i){int x;cin >> x;arr[x].first=i;}
    for (int i=1;i<=n;++i){int x;cin >> x;arr[x].second.first=i;}
    for (int i=1;i<=n;++i){int x;cin >> x;arr[x].second.second=i;}
    sort(arr.begin()+1,arr.begin()+1+n);

    for (int i=0;i<=100000;++i){bit[i]=1e9;}

    int ans=0;
    for (int i=1;i<=n;++i){
        if (get(arr[i].second.first) > arr[i].second.second){ans++;}
        update(arr[i].second.first,arr[i].second.second);
    }
    cout << ans;
}
