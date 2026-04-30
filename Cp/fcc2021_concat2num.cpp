#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[100005];

ll pw[10];

int sz(ll n){
    ll a=n;
    int s=0;
    while (a!=0){
        a/=10;s++;
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin >> t;
    pw[0]=1;
    pw[1]=10;
    for (int i=2;i<=16;++i){pw[i]=pw[i-1]*10;}
    while (t--){
        int n;cin >> n;
        ll l,r;cin >> l >> r;
        for (int i=1;i<=n;++i){cin >> arr[i];}
        sort(arr+1,arr+1+n);
        int a=sz(l);int b=sz(r);
        ll ans=0;
        for (int i=1;i<=n;++i){
             ll l1 = (l-arr[i]+pw[sz(arr[i])] - 1)/pw[sz(arr[i])];
             ll r1 = (r-arr[i])/pw[sz(arr[i])];
             int p1=lower_bound(arr+1,arr+1+n,l1)-arr;
             int p2=upper_bound(arr+1,arr+1+n,r1)-arr;
             --p2;
             ans+=max(0,(p2-p1+1));
        }
        cout << ans << '\n';
    }
}
