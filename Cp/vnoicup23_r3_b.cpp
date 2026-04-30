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

int vis[1005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int n,a,b; cin >> n >> a >> b;
        string s; cin >> s;

        int cnt0 = 0;
        for (int i = 0;i < s.size();++i){
            if (s[i] == '0') cnt0++;
        }
        if (a != b){cout << "YES" << '\n';}
        else{
            int x = 0;
            queue<int> q;
            q.push(x);
            while (q.size()){
                int val = q.front(); q.pop();
                if (val > n || val < 0 || vis[val]) continue;
                vis[val] = 1;
                for (int i = 1;i <= n - a + 1;++i){
                    int l = i; int r = i + a - 1;
                    if (val == 0){
                        q.push(r - l + 1);
                    }else{
                        int fval = val;
                        if (val >= l && val < r){
                            fval -= (val - l + 1);
                            fval += (r - val);
                        }else if (val >= l && val >= r){
                            fval -= (r - l + 1);
                        }else{
                            fval += (r - l + 1);
                        }
                        q.push(fval);
                    }
                }
            }
            cout << (vis[cnt0] ? "YES" : "NO") << '\n';
        }
        memset(vis,0,sizeof vis);
    }
}
