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

ll a[200005];

vector<ll> b[200005];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int n,k; cin >> n >> k;
        for (int i = 1;i <= n;++i){
            cin >> a[i];
        }

        for (int i = 0;i <= k/2;++i){
            for (int j = i;j <= n;j += k){
                if (j == 0){continue;}
                b[i].push_back(a[j]);
            }
            if (i == 0 || (i + i) % k == 0){continue;}
            for (int j = k - i;j <= n;j += k){
                b[i].push_back(a[j]);
            }
        }
        for (int i = 0;i <= k/2;++i){
            sort(b[i].begin(),b[i].end());
        }
        for (int i = 0;i <= k/2;++i){
            int l1 = i; int l2 = (k - i) % k;
            int dem = 0;
            while (1){
                if (l1 > n && l2 > n){break;}
                if (i == 0 || (i + i) % k == 0){
                    if (l1 != 0){a[l1] = b[i][dem++];}
                    l1 += k; l2 += k;
                }else{
                    if (l1 <= n) a[l1] = b[i][dem++];
                    if (l2 <= n) a[l2] = b[i][dem++];

                    l1 += k; l2 += k;
                }
            }
        }
        int check = 1;
        for (int i = 2;i <= n;++i){
            if (a[i] < a[i - 1]){
                check = 0;
                break;
            }
        }
        for (int i = 0;i <= k/2;++i){b[i].clear();}
        cout << (check ? "YES" : "NO") << '\n';
    }
}
