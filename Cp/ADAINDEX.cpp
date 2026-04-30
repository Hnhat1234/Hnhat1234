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

    void add(string s){
        int pos = 0;
        for (auto x:s){
            int c = x - 'a';
            if (node[pos].child[c] == -1){
                node[pos].child[c] = new_node();
            }
            pos = node[pos].child[c];
            node[pos].cnt++;
        }
        node[pos].exist++;
    }
};

trie a;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,q; cin >> n >> q;
    for (int i = 1;i <= n;++i){
        string s; cin >> s;
        a.add(s);
    }
    for (int i = 1;i <= q;++i){
        string s; cin >> s;
        int pos = 0;
        int check = 1;
        for (auto x:s){
            int c = x - 'a';
            if (a.node[pos].child[c] == -1){
                check = 0;
                break;
            }
            pos = a.node[pos].child[c];
        }
        cout << (check ? a.node[pos].cnt : 0) << '\n';
    }
}
