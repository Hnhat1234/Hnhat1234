#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[5005];

ll b[5005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,x; cin >> n >> x;

    pair<int,int> p[5005];
    for (int i = 1;i <= n;++i){
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(p + 1,p + 1 + n);

    for (int i = 1;i <= n;++i){
        a[i] = p[i].first;
        b[i] = p[i].second;
    }

    for (int i = 1;i <= n;++i){
        for (int j = i + 2;j <= n;++j){
            int p = lower_bound(a + i + 1,a + j,x - a[i] - a[j]) - a;
            if (p > i && p < j){
                if (a[i] + a[j] + a[p] == x){
                    cout << b[i] << ' ' << b[p] << ' ' << b[j];
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}
