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

ll dp[300005], f[100005], val[300005];

int p[300005];

struct trie{
    struct{
        int child[26];
        int exist, cnt;
    }node[1000005];

    int cur;
    trie() : cur(0){
        memset(node[0].child,-1,sizeof(node[cur].child));
        node[0].exist = node[0].cnt = 0;
    };

    int new_node(){
        cur++;
        memset(node[cur].child,-1,sizeof(node[cur].child));
        node[cur].exist = node[cur].cnt = 0;
        return cur;
    }

    void update(string s,int i){
        int pos = 0;
        for (auto x:s){
            int c = x - 'A';
            dp[i] = max(dp[i],val[pos] + p[i]);
            if(node[pos].child[c] == -1){
                node[pos].child[c] = new_node();
            }
            pos = node[pos].child[c];
            node[pos].cnt++;
        }
        val[pos] = max(val[pos],dp[i]);
        node[pos].exist++;
    }
};

trie a;

vector<int> b[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,m; cin >> n >> m;

    vector<string> str; str.push_back("0");
    for (int i = 1;i <= n;++i){
        string s; cin >> s;
        cin >> p[i];
        str.push_back(s);
    }

    for (int i = 1;i <= m;++i){
        int x,y; cin >> x >> y;
        b[x].push_back(y);
        b[y].push_back(x);
    }

    ll ans = 0;
    for (int i = n;i >= 1;--i){
        dp[i] = f[p[i]] + p[i];
        a.update(str[i],i);
        for (int v:b[p[i]]){
            f[v] = max(f[v],dp[i]);
        }
        ans = max(ans,dp[i]);
    }

    cout << ans;
}
