#include <bits/stdc++.h>
#define ll long long

using namespace std;

int bit[100005];

int n, ans[300005];

int getbit(int x){
    int ans=0;
    for (;x>0;x-=x&(-x)){
        ans+=bit[x];
    }
    return ans;
}
void update(int x){
    for (;x<=100000;x+=x&(-x)){
        bit[x]++;
    }
}
int main(){
    cin >> n;
    vector<pair<pair<ll,ll>,int>> h(n);
    for (int i=0;i<n;++i){
        cin >> h[i].first.first >> h[i].first.second;
        h[i].second = i;
    }
    sort(h.begin(),h.end());
    for (int i=0;i<n;++i){
        if (i == 0){
            ans[h[i].second] = getbit(h[i].first.second);
        }else{
            if (h[i].first.first == h[i - 1].first.first && h[i].first.second == h[i - 1].first.second){ans[h[i].second] = ans[h[i - 1].second];}
            else{
                ans[h[i].second] = getbit(h[i].first.second);
            }
        }
        update(h[i].first.second);
    }
    for (int i=0;i<n;++i){
        cout << ans[i] << '\n';
    }
}
