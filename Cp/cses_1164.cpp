#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

int ans[200005], n;

vector<pair<pair<int,int>,int>> p;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    cin >> n;

    for (int i = 0;i < n;++i){
        int a,b; cin >> a >> b; p.push_back({{b,a},i});
    }

    set<pair<int,int>> t;

    sort(p.begin(),p.end());

    for (int i = 0;i < n;++i){
        if (i == 0){t.insert({p[i].first.first,1}); ans[p[i].second] = 1;}
        else{

            int m = t.size();

            pair<int,int> s = {p[i].first.second,-1};


            if ((*t.begin()).first >= p[i].first.second){ans[p[i].second] = m + 1; t.insert({p[i].first.first,ans[p[i].second]});}
            else{
            auto p2 = lower_bound(t.begin(),t.end(),s); --p2;

            ans[p[i].second] = (*p2).second;


            }
        }
    }

    cout << t.size() << '\n';

    for (int i = 0;i < n;++i){cout << ans[i] << ' ';}
}
