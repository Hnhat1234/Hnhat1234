#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;
ll f[200001];
ll a[200001],b[200001];
ll i,n,m;
ll maximum(ll a,ll b){
    return a > b ? a : b;
}
int main(){
    freopen("lis.inp","r",stdin);
    freopen("lis.out","w",stdout);
    scanf("%lld",&n);
    for (i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    for (i=1;i<=n;++i){
        f[i] = lower_bound(b + 1,b + 1 + m,a[i])-b;
        m=maximum(m,f[i]);
        b[f[i]]=a[i];
    }
    printf("%lld",m);
}
