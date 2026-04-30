#include <bits/stdc++.h>
#define ll long long

using namespace std;

int c[50]; int vis[10][10];

int dequy(int x,int y,int p){
    if (vis[x][y - 1] && vis[x][y + 1] && (!vis[x - 1][y] && !vis[x + 1][y])){return 0;}
    if (vis[x - 1][y] && vis[x + 1][y] && (!vis[x][y - 1] && !vis[x][y + 1])){return 0;}

    if (x == 7 && y == 1){
        return (p == 48 ? 1 : 0);
    }

    if (p == 48){return 0;}

    int res = 0;

    vis[x][y] = 1;
    if (c[p] != '?'){
        if (c[p] == 'D' && !vis[x + 1][y]){res += dequy(x + 1,y,p + 1);}
        if (c[p] == 'L' && !vis[x][y - 1]){res += dequy(x,y - 1,p + 1);}
        if (c[p] == 'R' && !vis[x][y + 1]){res += dequy(x,y + 1,p + 1);}
        if (c[p] == 'U' && !vis[x - 1][y]){res += dequy(x - 1,y,p + 1);}
    }else{
        if (!vis[x + 1][y]){res += dequy(x + 1,y,p + 1);}
        if (!vis[x][y - 1]){res += dequy(x,y - 1,p + 1);}
        if (!vis[x][y + 1]){res += dequy(x,y + 1,p + 1);}
        if (!vis[x - 1][y]){res += dequy(x - 1,y,p + 1);}
    }
    vis[x][y] = 0;
    return res;
}
int main(){
     string s; cin >> s;

     for (int i = 0;i < 48;++i){
         c[i] = s[i];
     }

     for (int i = 0;i <= 8;++i){
        vis[0][i] = vis[i][0] = vis[8][i] = vis[i][8] = 1;
     }

     int ans = dequy(1,1,0);

     cout << ans << '\n';
}
