#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[200005];

ll b[200005];

int l[200005],r[200005];
int main(){
    int n;cin >> n;
    for (int i=1;i<=n;++i){cin >> a[i];}
    for (int i=1;i<n;++i){b[i]=abs(a[i+1]-a[i]);}
    stack<int> s;

    for (int i=1;i<n;++i){
        while (s.size()&&b[s.top()] < b[i]){s.pop();}
        if (s.size()){l[i]=s.top()+1;}
        else{l[i]=1;}
        s.push(i);
    }
    while (s.size()){s.pop();}
    for (int i=n-1;i>=1;--i){
        while (s.size()&&b[s.top()] <= b[i]){s.pop();}
        if (s.size()){r[i]=s.top()-1;}
        else{r[i]=n-1;}
        s.push(i);
    }
    ll ans=0;
    for (int i=1;i<n;++i){
        ans+=(b[i]*(i-l[i]+1)*(r[i]-i+1));
    }
    cout << ans;
}
