#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[1005];

int b[1005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n, x; cin >> n >> x;

    pair<ll,int> p[1005];

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
        for (int j = i + 3;j <= n;++j){
            ll s = x - a[i] - a[j];

            int l = i + 1; int r = j - 1;
            while (l < r){
                if (a[l] + a[r] < s){++l;}
                else if (a[l] + a[r] > s){--r;}
                else{break;}
            }

            if (l < r){
                cout << b[i] << ' ' << b[j] << ' ' << b[l] << ' ' << b[r];
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
