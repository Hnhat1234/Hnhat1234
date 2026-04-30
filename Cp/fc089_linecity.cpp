#include <bits/stdc++.h>

using namespace std;

long long a[100005];
int main(){
    long long l,n; cin >> l >> n;

    for (int i = 1;i <= n;++i) cin >> a[i];

    sort(a + 1,a + 1 + n);
    long long ans = 0;
    for (int i = 1;i < n;++i){
        if (a[i + 1] - a[i] > 1){
           long long m = (a[i] + a[i + 1])/2;
           ans = max(ans,min(abs(a[i] - m),abs(a[i + 1] - m)));
        }
    }

    ans = max(ans,max(a[1],l - a[n]));

    cout << ans;
}
