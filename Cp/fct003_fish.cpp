#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll pre[405][405];

ll a[405][405];

ll x[405]; int y[405];

ll get(int x1,int y1,int x2,int y2){
    return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}
int main(){
    int n,m; cin >> n >> m;

    for (int i = 1;i <= n;++i){cin >> x[i];}
    for (int i = 1;i <= m;++i){cin >> y[i];}

    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= m;++j){
            cin >> a[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }

    ll res = 0;

    for (int i = 1;i <= n;++i){
        for (int j = i;j <= n;++j){
            ll temp = 1e18;
            for (int k = 1;k <= m;++k){
                if (k == 1){temp = -(x[j] - x[i])*y[k];}
                else{temp = min(temp,get(i,1,j,k - 1) - (x[j] - x[i])*y[k]);}

                res = max(res,get(i,1,j,k) - (x[j] - x[i])*y[k] - temp);
            }
        }
    }

    cout << res;
}
