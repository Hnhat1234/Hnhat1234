#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n, m, k;cin >> n >> m >> k;

    if (n > m){swap(n,m);}

    ll ans = 1;

    ll temp = n/k;

    ans += k*temp*(temp+1)/2 + temp;

    ll l = (n + 1)/k + ((n + 1)%k!=0);

    ll r = m/k;

    ans+=max((r - l + 1),0LL)*(n + 1);

    l = (m + 1)/k + ((m + 1)%k!=0); r = (n + m)/k;

    ans+=(r - l + 1)*(n + m + 1) - k*(r*(r + 1)/2 - l*(l - 1)/2);

    cout << ans;
}
