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

int bit[200005], f[200005][15], a[200005];

int lim[200005];

void xuly(int i,ll x){
    int dem = 0;
    while (1){
        f[i][dem++] = x;
        ll temp = x;
        ll s = 0;
        while (temp != 0){
            s += (temp % 10);
            temp /= 10;
        }
        if (s == x){break;}
        else{
            x = s;
        }
    }
    lim[i] = dem;
}
void update(int n,int i,int value){
    while (i <= n){
        bit[i] += value;
        i += (i & (-i));
    }
}
ll get(int x){
    int res = 0;
    while (x > 0){
        res += bit[x];
        x -= (x & (-x));
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int n,q; cin >> n >> q;
        for (int i = 1;i <= n;++i){
            bit[i] = 0;
            cin >> a[i];
            ll x = a[i];
            xuly(i,x);
        }
        while (q--){
            int type; cin >> type;
            if (type == 1){
                int l,r; cin >> l >> r;
                update(n,l,1);
                update(n,r + 1,-1);
            }else{
                int x; cin >> x;
                int total = get(x);
                cout << (total >= lim[x] ? f[x][lim[x] - 1] : f[x][total]) << '\n';
            }
        }
    }
}
