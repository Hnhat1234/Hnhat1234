#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[300005], pre[300005];

int consecutive[300005], r[300005];
int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 1;i <= n;++i){
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        ll x = a[1];
        for (int i = 1;i <= n;++i){
            if (x == a[i]){consecutive[i] = consecutive[i - 1] + 1;}
            else{
                x = a[i];
                consecutive[i] = 1;
            }
        }
        x = a[n]; r[n + 1] = 0;
        for (int i = n;i >= 1;--i){
            if (x == a[i]){r[i] = r[i + 1] + 1;}
            else{
                x = a[i];
                r[i] = 1;
            }
        }
        for (int i = 1;i <= n;++i){
            int c = 4e5;
            if (i > 1){
                int pos = lower_bound(pre, pre + i, pre[i - 1] - a[i]) - pre;
                pos -= 1;
                if (pos >= 0 && consecutive[i] != i){
                    if (a[i - 1] > a[i]){c = 1;}
                    else if (consecutive[i - 1] > 1 && consecutive[i - 1] == i - 1){}
                    else{
                        c = min(c,max(i - pos - 1,consecutive[i - 1] + 1));
                        if (i == 2 || (i - pos - 1 == 1 && a[i] != a[i - 1])){c = 1;}
                    }
                }
            }
            if (i < n){
                int pos = upper_bound(pre + i + 1,pre + n + 1,pre[i] + a[i]) - pre;
                if (pos <= n && r[i] != n - i + 1){
                    if (a[i + 1] > a[i]){c = 1;}
                    else if (r[i + 1] > 1 && r[i + 1] == n - i){}
                    else{
                        c = min(c,max(pos - i,r[i + 1] + 1));
                        if (i == n - 1 || (pos - i == 1 && a[i] != a[i + 1])){c = 1;}
                    }
                }
            }
            cout << (c == 4e5 ? -1 : c) << ' ';
        }
        cout << '\n';
    }
}
