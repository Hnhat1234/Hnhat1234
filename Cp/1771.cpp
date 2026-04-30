#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define maxi(a, b) a = max(a, b)
#define mize(a, b) a = min(a, b)
#define getbit(a, i) ((a) >> (i) & 1)

#define FOR(i, a, b) for(int i=a, _n=b; i<=_n; ++i)
#define FORD(i, a, b) for(int i=a, _n=b; i>=_n; --i)
#define REP(i, _n) for(int i=0; i<_n; ++i)

#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair

#define ii pair<int, int>

using namespace std;

const ll basehash = 31;
const ll modhash = 1000000003;

char a[405][405];

ll pre[405][405][4];

ll up1[405][405], down1[405][405];

ll up2[405][405], down2[405][405];

void process(int n,int m){
    for (int i = 1;i <= m;++i){
        up1[0][i] = up2[0][i] = 0;
        for (int j = 1;j <= n;++j){
            if (a[j - 1][i] == '#' && j - 1 > 0){up1[j][i] = j - 1;}
            else{
                up1[j][i] = up1[j - 1][i];
            }

            if (a[j - 1][i] == 'm' && j - 1 > 0){
                up2[j][i] = j - 1;
            }else{
                up2[j][i] = up2[j - 1][i];
            }
        }
        down1[n + 1][i] = down2[n + 1][i] = n + 1;
        for (int j = n;j >= 1;--j){
            if (a[j + 1][i] == '#' && j + 1 <= n){down1[j][i] = j + 1;}
            else{
                down1[j][i] = down1[j + 1][i];
            }

            if (a[j + 1][i] == 'm' && j + 1 <= n){
                down2[j][i] = j + 1;
            }else{
                down2[j][i] = down2[j + 1][i];
            }
        }
    }
}
ll tinh(int i,int j,int k,int n,int m){
    ll l = max(max(up1[i][j],up2[i][j]),max(up1[i][k],up2[i][k]));
    ll r = min(min(down1[i][j],down2[i][j]),min(down1[i][k],down2[i][k]));

    ll res = 0;
    int check = 0;
    if (i - l - 1 > 0 && r - i - 1 > 0){
        check = 1;
        res = r - l - 1;
    }
    if (pre[i][k][2] - pre[i][j - 1][2] == 0){
        if (a[l][j] == 'm' && a[l][k] == '.'){
            int l1 = max(max(up1[l][j],up2[l][j]),max(up1[l][k],up2[l][k]));
            if (i - l1 - 1 > 0 && r - i - 1 > 0){
                check = 1;
                res = max(res,r - l1 - 1);
            }
        }
        if (a[l][j] == '.' && a[l][k] == 'm'){
            int l1 = max(max(up1[l][k],up2[l][k]),max(up1[l][j],up2[l][j]));
            if (i - l1 - 1 > 0 && r - i - 1 > 0){
                check = 1;
                res = max(res,r - l1 - 1);
            }
        }
        if (a[r][j] == 'm' && a[r][k] == '.'){
            int r1 = min(min(down1[r][j],down2[r][j]),min(down1[r][k],down2[r][k]));
            if (i - l - 1 > 0 && r1 - i - 1 > 0){
                check = 1;
                res = max(res,r1 - l - 1);
            }
        }
        if (a[r][j] == '.' && a[r][k] == 'm'){
            int r1 = min(min(down1[r][k],down2[r][k]),min(down1[r][j],down2[r][j]));
            if (i - l - 1 > 0 && r1 - i - 1 > 0){
                check = 1;
                res = max(res,r1 - l - 1);
            }
        }
    }
    return (check ? 2 * res + (k - j - 1) : 0);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m; cin >> n >> m;
    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= m;++j){
            cin >> a[i][j];

        }
    }

    process(n,m);
    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= m;++j){
            pre[i][j][2] = pre[i][j - 1][2] + (a[i][j] == 'm');
            pre[i][j][1] = pre[i][j - 1][1] + (a[i][j] == '#');
        }
    }

    ll ans = 0;
    for (int i = 2;i < n;++i){
         for (int j = 1;j <= m;++j){
            for (int k = j + 2;k <= m;++k){
                if (pre[i][k][1] - pre[i][j - 1][1]) continue;
                if (pre[i][k][2] - pre[i][j - 1][2] >= 2) continue;
                ans = max(ans,tinh(i,j,k,n,m));
            }
         }
    }
    cout << ans;
}
