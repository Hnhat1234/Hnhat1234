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

ll d[300005];

int cnt[300005], a[300005];

int snt[300005];

vector<vector<int>> p(300005);

vector<vector<int>> prime(300005);

int type[300005];

int vis[300005];

int trace[300005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        cnt[a[i]] = 1;
        type[a[i]] = i;
    }
    int s,t; cin >> s >> t;
    type[a[s]] = s; type[a[t]] = t;
    if (s == t){cout << 1 << '\n'; cout << s; return 0;}
    else if (a[s] == 1 || a[t] == 1){cout << -1; return 0;}
    else if (a[s] == a[t]){cout << 2 << '\n'; cout << s << ' ' << t; return 0;}
    for (int i = 2;i <= 300000;++i){
        if (snt[i]) continue;

        prime[i].push_back(i);
        if (cnt[i]){p[i].push_back(i);}
        for (int j = 2 * i;j <= 300000;j += i){
            snt[j] = 1;
            prime[j].push_back(i);
            if (cnt[j]){
                p[i].push_back(j);
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({a[s],a[s]});
    for (int i = 1;i <= 300000;++i){d[i] = 1e9;}
    d[a[s]] = 0;
    while (q.size()){
        auto x = q.front(); q.pop();

        if (x.first == a[t]){
            vis[x.first] = 1;
            trace[x.first] = x.second;
            break;
        }
        if (vis[x.first]){continue;}
        vis[x.first] = 1;
        int temp = x.first;
        for (auto i : prime[x.first]){
            for (auto val : p[i]){
                if (val == i){continue;}
                if (d[val] > d[x.first] + 1){
                    d[val] = d[x.first] + 1;
                    trace[val] = x.first;
                    q.push({val,x.first});
                }
            }
        }
    }
    if (vis[a[t]] == 0){cout << -1;}
    else{
        int temp = a[t];
        vector<int> ans;
        while (1){
            ans.push_back(type[temp]);
            temp = trace[temp];
            if (a[s] == temp){
                ans.push_back(type[a[s]]);
                break;
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() << '\n';
        for (int i = 0;i < ans.size();++i){
            cout << ans[i] << ' ';
        }
    }
}
