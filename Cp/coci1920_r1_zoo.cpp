#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[1005][1005], d[1005][1005];

int d1[4] = {1,0,-1,0};

int d2[4] = {0,-1,0,1};

int n, m, ans;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;

    for (int i = 1;i <= n;++i){
        string s; cin >> s;
        for (int j = 1;j <= m;++j){
            a[i][j] = s[j - 1];
        }
    }

    memset(d,-1,sizeof(d));
    queue<pair<int,int>> q[2];

    d[1][1] = 1;

    int type = 0;

    q[type].push({1,1});

    while (q[0].size() || q[1].size()){
        int s = q[type].front().first;

        int t = q[type].front().second;

        ans = max(ans,d[s][t]);
        q[type].pop();

        for (int i = 0;i < 4;++i){
            int dx = d1[i] + s;
            int dy = d2[i] + t;

            if (dx <= 0 || dy <= 0 || dx > n || dy > m) continue;
            if (a[dx][dy] == a[s][t] && d[dx][dy] == -1){
                d[dx][dy] = d[s][t];
                q[type].push({dx,dy});
            }
            else if (a[dx][dy] != '*' && a[s][t] != '*' && d[dx][dy] == -1){
                d[dx][dy] = d[s][t] + 1;
                q[1 - type].push({dx,dy});
            }
        }
        if (!q[type].size()) type = 1 - type;
    }

    cout << ans;
}
