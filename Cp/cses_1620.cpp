#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p[200005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n, t; cin >> n >> t;;

    for (int i = 0;i < n;++i){cin >> p[i];}

    ll l = 1; ll r = 1e18;

    while (l <= r){
        ll mid = (r - l)/2 + l;

        ll temp = 0; int check = 0;

        for (int i = 0;i < n;++i){
            temp += mid/p[i];
            if (temp >= t){check = 1; r = mid - 1; break;}
        }

        if (!check){l = mid + 1;}
    }

    cout << l;
}
