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

ll mod = 1e9 + 9;

ll p[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,k; cin >> n >> k;
    string s; cin >> s;
    s = ' ' + s;

    int ques = 0;

    p[0] = 1;
    for (int i = 1;i <= n;++i){p[i] = (p[i - 1] * 2LL) % mod; ques += (s[i] == '?');}

    int cur1 = 0; int cur0 = 0; int cur_ques = 0;

    ll ans = 0;
    for (int i = 1;i <= n;++i){
        if (s[i] == '0'){cur0 += 1;}
        if (s[i] == '1'){cur1 += 1;}
        if (s[i] == '?'){cur_ques += 1;}

        if (i > k){
            if (s[i - k] == '0'){cur0--;}
            if (s[i - k] == '1'){cur1--;}
            if (s[i - k] == '?'){cur_ques--;}
        }
        if (i >= k && (cur1 + cur_ques == k)){
            ans = (ans + p[ques - cur_ques]) % mod;
        }
    }
    cout << ans;
}
