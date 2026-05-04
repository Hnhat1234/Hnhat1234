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

int cnt[10];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        for (int i = 0;i <= 9;++i){cnt[i] = 0;}
        int n; cin >> n;
        for (int i = 0;i < n;++i){
            ll x; cin >> x;
            cnt[x % 10]++;
        }
        bool check = 0;
        for (int i = 0;i <= 9;++i){
            for (int j = 0;j <= 9;++j){
                for (int k = 0;k <= 9;++k){
                    if (((i + j) % 10 + k) % 10 != 3){continue;}
                    if (i != j && j != k && i != k){check = max(check,(cnt[i] && cnt[j] && cnt[k]));}
                    if (i == j && j == k){check = max(check,(cnt[i] >= 3));}
                    if (i == j && j != k){check = max(check,(cnt[i] >= 2 && cnt[k]));}
                    if (i == k && i != j){check = max(check,(cnt[i] >= 2 && cnt[j]));}
                    if (j == k && i != j){check = max(check,(cnt[j] >= 2 && cnt[i]));}
                }
            }
        }
        cout << (check ? "YES" : "NO") << '\n';
    }
}
