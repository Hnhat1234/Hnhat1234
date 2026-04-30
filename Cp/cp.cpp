#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[100005],b[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin >> n;
    ll l=-1,r=2e8;
    for (int i=1;i<=n;++i){cin >> a[i];}
    int m;cin >> m;
    for (int i=1;i<=m;++i){cin >> b[i];}
    while (r-l>1){
        ll mid=(l+r)/2;
        vector<ll> v;
        for (int i=1;i<=n;++i){
            if (a[i] < mid){v.push_back(mid-a[i]);}
        }
        int p=0;
        for (int i=1;i<=m;++i){
            if (p==v.size()){break;}
            if (b[i] >= a[p]){p++;}
        }
        if (p==v.size()){l=mid;}
        else{
            r=mid;
        }
    }
    cout << l;
}
