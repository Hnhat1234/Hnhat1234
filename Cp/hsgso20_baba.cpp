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

ll cnt[40];

ll p[1000005];

int l,r;

vector<int> pos[40];

bool cmp(string a,string b){
    if (a.size() != b.size()){return a.size() > b.size();}
    else{
        return a > b;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    p[0] = 1;
    for (int i = 1;i <= n;++i){p[i] = (p[i - 1] * 10) % 33;}
    cnt[0] = 1;

    ll cur = 0;

    ll ans1 = 0;
    pos[0].push_back(0);
    for (int i = 1;i <= n;++i){
        cur = (cur * 10 + s[i] - '0') % 33;
        ll mod = cur * p[n - i] % 33;
        ans1 += cnt[mod];
        cnt[mod]++;
        pos[mod].push_back(i);
    }
    int t; cin >> t;
    if (t == 1){cout << ans1;}
    else{
        vector<string> res;
        for (int i = 0;i < 33;++i){
            if (pos[i].size() > 1){
                res.push_back(s.substr(pos[i][0] + 1,pos[i].back() - pos[i][0]));
            }
        }
        sort(res.begin(),res.end(),cmp);
        if (res.size()){cout << res[0];}
        else{
            cout << -1;
        }
    }

}
