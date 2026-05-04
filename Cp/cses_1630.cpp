#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;

    ll ans = 0;

    vector<pair<int,int>> p;
    for (int i = 0;i < n;++i){
        int a,d; cin >> a >> d;
        p.push_back({a,d});

        ans += d;
    }

    sort(p.begin(),p.end());

    for (int i = 0;i < n;++i){
        ans -= 1LL*(n - i)*p[i].first;
    }

    cout << ans;
}
