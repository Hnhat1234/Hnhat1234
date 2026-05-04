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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,q; cin >> n >> q;
    string s; cin >> s;
    vector<int> b;
    s = ' ' + s;
    for (int i = 2;i < s.size();++i){
        if (s[i] == ')' && s[i - 1] == '('){
            b.push_back(i - 1);
        }
    }
    while (q--){
        int l,r; cin >> l >> r;
        if (r - l + 1 <= 1){cout << -1 << '\n';}
        else{
            int p = lower_bound(b.begin(),b.end(),l) - b.begin();
            if (p >= b.size()){cout << -1 << '\n';}
            else{
                cout << b[p] << ' ' << b[p] + 1 << '\n';
            }
        }
    }
}
