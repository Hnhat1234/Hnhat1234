#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("O2")

using namespace std;

const ll basehash = 31;
const ll modhash = 1000000003;

const ll maxn = 200005;

ll a[maxn], b[maxn], x[maxn];

ll st[25][maxn], lg2[maxn];

void BuildLog2Array() {
    lg2[1] = 0;
    for (int i = 2; i < maxn; ++i)
        lg2[i] = lg2[i / 2] + 1;
}
void preprocess(int n) {
    for (int i = 1; i <= n; ++i) st[0][i] = b[i];
    for (int j = 1; j <= 17; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
ll queryMin(int l, int r){
    int k = lg2[r - l + 1];
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    BuildLog2Array();
    while (t--){
        int n; cin >> n;
        for (int i = 1;i <= n;++i){cin >> a[i];}
        for (int i = 1;i <= n;++i){cin >> b[i];}
        preprocess(n);
        int m; cin >> m;
        unordered_map<ll,ll> appear,cnt,pos;
        for (int i = 1;i <= m;++i){
            cin >> x[i];
            appear[x[i]] += 1;
        }
        int check = 1;
        for (int i = 1;i <= n;++i){
            if (a[i] < b[i]){check = 0; break;}
        }
        if (!check){cout << "NO" << '\n';}
        else{
            ll check = 1; ll ans = 0;
            for (int i = 1;i <= n;++i){
                if (a[i] != b[i]){
                   if (cnt[b[i]] > appear[b[i]]){check = 0; break;}
                   if (pos[b[i]] == 0){
                       ans += 1; pos[b[i]] = i; cnt[b[i]] = 1;
                       if (cnt[b[i]] > appear[b[i]]){check = 0; break;}
                       continue;
                   }
                   if (queryMin(pos[b[i]],i) > b[i]){ans += 1; cnt[b[i]] += 1;}
                   if (cnt[b[i]] > appear[b[i]]){check = 0; break;}
                   pos[b[i]] = i;
                }
            }
            cout << (ans <= m && check ? "YES" : "NO") << '\n';
        }
    }
}
