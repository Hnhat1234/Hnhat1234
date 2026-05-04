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

vector<ll> b;

ll f[10005][(1 << 8) + 5], a[15][10005], cost[(1 << 8) + 5][10005];

void init(){
    for (int i = 0;i < (1 << 8);++i){
        ll temp = i;
        vector<ll> a;
        while (temp != 0){
            a.push_back(temp % 2);
            temp/=2;
        }
        int check = 1;
        for (int i = 1;i < a.size();++i){
            if (a[i] + a[i - 1] == 2){check = 0; break;}
        }
        if (check){b.push_back(i);}
    }
}
void process(int n){
    for (int i = 0;i < n;++i){
       for (int j = 0;j < b.size();++j){
       ll temp = b[j];
       vector<ll> bit;
       while (temp != 0){
           bit.push_back(temp % 2);
           temp/=2;
       }
       while (bit.size() < 8){bit.push_back(0LL);}

       ll res = 0;
       for (int z = 0;z < bit.size();++z){res += bit[z] * a[z][i];}
       cost[b[j]][i] = res;
      }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    init();
    int n; cin >> n;

    memset(f,-1e18,sizeof f);

    for (int i = 0;i < 8;++i){
        for (int j = 0;j < n;++j){
            cin >> a[i][j];
        }
    }
    process(n);

    for (int i = 0;i < n;++i){
        for (int j = 0;j < b.size();++j){
            if (i == 0){f[i][b[j]] = cost[b[j]][i]; continue;}
            for (int k = 0;k < b.size();++k){
                if (b[k] & b[j]) continue;

                f[i][b[k]] = max(f[i][b[k]],f[i - 1][b[j]] + cost[b[k]][i]);
            }
        }
    }

    ll ans = -1e18;
    for (int i = 0;i < b.size();++i){
        ans = max(ans,f[n - 1][b[i]]);
    }
    cout << ans;
}
