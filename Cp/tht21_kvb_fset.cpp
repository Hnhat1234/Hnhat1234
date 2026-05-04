#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[1000005];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n, mod; cin >> n >> mod;

    for (int i = 1; i <= n; ++i){a[i] = i;}

    for (int i = 2;i <=sqrt(n) ;++i){
        ll temp = i*i;
        for (int j = temp; j <= n ;j += temp){
            while (a[j]%temp==0){a[j]/=temp;}
        }
    }

    sort(a+1,a+1+n);

    ll ans=1;ll cnt=1;

    for (int i = 2 ;i <= n;++i){
        if (a[i]==a[i-1]){cnt++;}
        else{
            ans=(ans*(cnt+1))%mod;cnt=1;
        }
    }

    ans=(ans*(cnt+1))%mod;cnt=1;

    cout << ans;
}
