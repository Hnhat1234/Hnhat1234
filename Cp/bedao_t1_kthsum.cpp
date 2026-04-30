#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll bit[100005];

ll prefix[100005];

ll a[100005];

ll b[100005];

int get(int u){
    int s = 0;

    while (u > 0){
        s += bit[u];

        u-=(u&(-u));
    }
    return s;
}

void update(int u,int n){
    while (u <= n){
        ++bit[u];

        u+=(u&(-u));
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n;cin >> n; ll k;cin >> k;

    for (int i = 1;i <= n;++i){
        ll x;cin >> x;
        prefix[i] = prefix[i - 1] + x;

        a[i] = prefix[i];
    }

    sort(a + 1,a + 1 + n);

    for (int i = 1;i <= n;++i){
        b[i] = lower_bound(a + 1,a + 1 + n,prefix[i]) - a;
    }

    ll l = -1e14; ll r = 1e14;

    a[n + 1] = 1e18;
    while (l <= r){
        memset(bit,0,sizeof bit);

        ll mid = (l + r)/2; ll temp = 0;
        for (int i = 1;i <= n;++i){
            int m = upper_bound(a + 1,a + 1 + n,prefix[i] - mid) - a;

            m--;

            temp+=get(m) + (prefix[i] >= mid);

            update(b[i],n);
        }

        if (temp >= k){l = mid+1;}
        else{r = mid - 1;}
    }

    cout << r;
}
