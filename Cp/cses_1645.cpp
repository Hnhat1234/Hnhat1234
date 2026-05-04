#include <bits/stdc++.h>
#define ll long long

using namespace std;

int ans[200005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;

    pair<int,int> p[200005];

    for (int i = 1;i <= n;++i){
        cin >> p[i].first;

        p[i].second = i;
    }
    sort(p + 1,p + 1 + n);

    set<int> s;

    for (int i = 1;i <= n;++i){
        if (i == 1){ans[p[i].second] = 0; s.insert(p[i].second);}
        else if (p[i].first != p[i - 1].first){
            s.insert(p[i].second);

            auto p2 = lower_bound(s.begin(),s.end(),p[i].second);
            if (p2 == s.begin()){ans[p[i].second] = 0;}
            else{
                ans[p[i].second] = (*(--p2));
            }
        }else{
            ans[p[i].second] = p[]
            s.insert(p[i].second);
        }
    }

    for (int i = 1;i <= n;++i){
        cout << ans[i] << ' ';
    }
}
