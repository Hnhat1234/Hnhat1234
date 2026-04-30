#include <bits/stdc++.h>
#define ll long long

using namespace std;

int pre[405][405];

int a[405][405];

int cnt[255];

int get(int x1,int y1,int x2,int y2){
    return (x1 <= x2 && y1 <= y2 ? pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1] : 0);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k;cin >> n >> m >> k;
    for (int i=1;i<=n;++i){
        string s;cin >> s;
        for (int j=1;j<=m;++j){
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+(s[j-1]=='z');
            a[i][j]=s[j-1];
        }
    }

    long long ans=0;

    for (int x = 1; x <= n;++x){
        for (int y = x; y <= n;++y){
            memset(cnt,0,sizeof(cnt));
            for (int l=1,r=0;l <= m;++l){
                while (r < m && get(x,l,y,r+1) <= k){
                    cnt[a[x][++r]] += (a[x][r] == a[y][r]);
                }

                if (a[x][l] == a[y][l]){
                   ans+=max(0,cnt[a[x][l]]--);
                }
            }
        }
    }

    cout << ans;
}
