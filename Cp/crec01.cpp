#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[1005][1005];

int h[1005];

int l[1005], r[1005];

int p[1005];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,m; cin >> n >> m;

    for (int i = 1;i <= n;++i){
        string s; cin >> s;
        for (int j = 1;j <= m;++j){
            a[i][j] = s[j - 1];
        }
    }

    ll ans = 0;

    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= m;++j){h[j] = (a[i][j] == '0' ? 0 : h[j] + 1); p[h[j]] = 0;}

        stack<int> sr;

        for (int j = m;j >= 1;--j){
            while (!sr.empty() && h[sr.top()] >= h[j]){sr.pop();}
            if (sr.empty()){r[j] = m; sr.push(j);}
            else{r[j] = sr.top() - 1; sr.push(j);}
        }

        stack<int> sl;
        for (int j = 1;j <= m;++j){
            while (!sl.empty() && h[sl.top()] >= h[j]){sl.pop();}
            if (sl.empty()){
                l[j] = 1; sl.push(j);
            }else{l[j] = sl.top() + 1; sl.push(j);}

            if (l[j] > p[h[j]]){ans += (r[j] - l[j] + 1)*(r[j] - l[j] + 2)/2*h[j];}

            p[h[j]] = j;
        }
    }

    cout << ans;
}
