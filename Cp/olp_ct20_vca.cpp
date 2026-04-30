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

int cnt1[255];

int cnt2[255];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int k; cin >> k;
    string s; cin >> s;

    int n = s.size();
    s = ' ' + s;
    for (int i = 1;i <= n;++i){cnt1[s[i]]++; cnt2[s[i]]++;}

    if (cnt1['C'] < k || cnt1['V'] < k || cnt1['A'] < k){cout << -1; return 0;}

    int r = n;
    while (cnt2[s[r]] - 1 >= k){cnt2[s[r]]--; r--;}

    int ans = 1e9;
    for (int i = 1;i <= n;++i){
        if (cnt2[s[i]] > k){
            cnt2[s[i]]--; ans = min(ans,r - i - 3 * k);
        }else{
            while (cnt2[s[i]] <= k && r < n){cnt2[s[r + 1]]++; r++;}
            if (cnt2[s[i]] <= k && i == 1){ans = min(ans,n - 3 * k); break;}
            if (cnt2[s[i]] <= k) break;

            cnt2[s[i]]--;
            ans = min(ans,r - i - 3 * k);
        }
    }
    cout << ans;

}
