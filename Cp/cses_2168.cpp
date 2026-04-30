#include <bits/stdc++.h>
#define ll long long
#define pa pair<pair<int,int>,int>

using namespace std;

int a[200005], b[200005];

bool cmp(pa a1,pa b){
    return (a1.first.first < b.first.first || (a1.first.first == b.first.first && a1.first.second > b.first.second));
}
int main(){
    vector<pair<pair<ll,ll>,int>> p;

    int n; cin >> n;

    for (int i = 0;i < n;++i){
        ll x,y; cin >> x >> y;
        p.push_back({{x,y},i});
    }

    sort(p.begin(),p.end(),cmp);
    ll mi = p[n - 1].first.second;
    for (int i = n - 2;i >= 0;--i){
        a[p[i].second] = (p[i].first.second >= mi);
        mi = min(mi,p[i].first.second);
    }
    ll ma = p[0].first.second;
    for (int i = 1;i < n;++i){
        b[p[i].second] = (p[i].first.second <= ma);
        ma = max(ma,p[i].first.second);
    }

    for (int i = 0;i < n;++i){cout << a[i] << ' ';}cout << '\n';
    for (int i = 0;i < n;++i){cout << b[i] << ' ';}
}
