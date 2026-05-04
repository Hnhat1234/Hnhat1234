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

vector<vector<int>> p(200005);

int b[200005] ,a[200005];

bool cmp(int i,int j){
    if (p[i][p[i].size() - 1] < p[j][p[j].size() - 1]){return true;}
    else if (p[i][p[i].size() - 1] == p[j][p[j].size() - 1]){
        return p[i][0] < p[j][0];
    }
    return false;
}

int dp[200005], pre[200005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
         int n; cin >> n;
         for (int i = 1;i <= n;++i){
            dp[i] = pre[i] = 0;
            b[i] = i;
            int k; cin >> k;
            for (int j = 1;j <= k;++j){
                ll x; cin >> x;
                if (p[i].size() == 0){p[i].push_back(x);}
                else{
                    if (x > p[i][p[i].size() - 1]){p[i].push_back(x);}
                }
            }
            b[i] = i;
         }
         sort(b + 1,b + 1 + n,cmp);
         for (int i = 1;i <= n;++i){a[i] = p[b[i]][p[b[i]].size() - 1];}
         for (int i = 1;i <= n;++i){
            for (int j = 0;j < p[b[i]].size();++j){
                int x = lower_bound(a + 1,a + 1 + n,p[b[i]][j]) - a;
                x--;
                dp[i] = max(dp[i],pre[x] + (int)p[b[i]].size() - j);
            }
            pre[i] = max(pre[i - 1],dp[i]);
         }
         int ans = 0;
         for (int i = 1;i <= n;++i){
            ans = max(ans,dp[i]);
            p[i].clear();
         }
         cout << ans << '\n';
    }
}
