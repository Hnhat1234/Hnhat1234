#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll d[20];

int p[5];

int m[405][405];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n;cin >> n;

    p[0] = 1;
    for (int i = 1;i <= 3;++i){
        p[i] = p[i - 1] * 2;
    }

    for (int i = 1;i <= n;++i){
        int x,y,c;
        cin >> x >> y >> c;
        m[x + 200][y + 200] = c;
    }

    ll ans = 0;

    for (int i = 0;i <= 400;++i){
        for (int j = i + 1;j <= 400;++j){
            memset(d,0,sizeof d);
            for (int k = 0;k <= 400;++k){
                if (!m[i][k] || !m[j][k]){continue;}
                if (m[i][k] == m[j][k]){continue;}

                int temp = p[m[i][k] - 1] + p[m[j][k] - 1];
                ans += d[15 - temp];
                ++d[temp];
            }
        }
    }

    cout << ans;
}
