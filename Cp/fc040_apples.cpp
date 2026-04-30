#include <bits/stdc++.h>
#define ll long long

using namespace std;

int pre[15][50005];

int a[50005][15];

int ans[50005][15];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int m,n; cin >> m >> n;
    for (int i = 1;i <= m;++i){
        string s; cin >> s;
        for (int j = 1;j <= n;++j){
            a[i][j] = s[j - 1];

            pre[j][i] = pre[j][i - 1] + (s[j - 1] == 'a');

            if (s[j - 1] == '.' || s[j - 1] == '#'){ans[i][j] = s[j - 1];}
            else{ans[i][j] = '.';}
        }
    }

    for (int i = 1;i <= n;++i){
        for (int l = 0,r = 1;r <= m;){
            if (a[r][i] == '#'){r += 1; l = r - 1;}
            else{
              while (a[r][i] != '#' && r <= m){r += 1;}

              for (int j = r - 1;j > r - 1 - (pre[i][r - 1] - pre[i][l]);--j){ans[j][i] = 'a';}

              l = r;
            }
        }
    }

    for (int i = 1;i <= m;++i){
        for (int j = 1;j <= n;++j){
            cout << (char)ans[i][j];
        }
        cout << '\n';
    }
}
