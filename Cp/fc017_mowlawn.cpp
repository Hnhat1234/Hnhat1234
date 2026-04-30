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

ll p[100005], e[100005];

ll st[400005], f[100005];

ll q[400005];

void update1(int id,int l,int r,int i){
    if (l > i || r < i){return;}
    if (l == r){st[id] = f[l]; return;}
    int m = (l + r)/2;
    update1(id * 2,l,m,i);
    update1(id * 2 + 1,m + 1,r,i);
    st[id] = max(st[id * 2],st[id * 2 + 1]);
}

void update2(int id,int l,int r,int i,ll k){
    if (l > i || r < i){return;}
    if (l == r){q[id] = k; return;}

    int m = (l + r)/2;
    update2(id * 2,l,m,i,k);
    update2(id * 2 + 1,m + 1,r,i,k);
    q[id] = max(q[id * 2] , q[id * 2 + 1]);
}

ll get1(int id,int l,int r,int u,int v){
     if (l > v || r < u){return -1e9;}
     if (l >= u && r <= v){return st[id];}

     int m = (l + r)/2;
     return max(get1(id * 2,l,m,u,v),get1(id * 2 + 1,m + 1,r,u,v));
}

ll get2(int id,int l,int r,int u,int v){
     if (l > v || r < u){return 0;}
     if (l >= u && r <= v){return q[id];}

     int m = (l + r)/2;
     return max(get2(id * 2,l,m,u,v),get2(id * 2 + 1,m + 1,r,u,v));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    memset(st,-1e15,sizeof(st));
    int n,k; cin >> n >> k;
    for (int i = 1;i <= n;++i){
        cin >> e[i];
        p[i] = p[i - 1] + e[i];
    }

    p[n + 1] = p[n];
    ll ans = 0;
    for (int i = 1;i <= n + 1;++i){
        if (i == n + 1){
            ans = max(ans,get2(1,1,n,n - 1,n - k - 1));
        }
        if (i <= k + 1){ans = max(ans,p[i - 1]); f[i] = p[i - 1] - p[i]; update1(1,1,n,i); update2(1,1,n,i,p[i - 1]);}
        else{

            ll s = p[i] + get1(1,1,n,i - k,i - 1);

            ans = max(ans,s);
            f[i] = get2(1,1,n,i - k,i - 1) - p[i];

            update1(1,1,n,i);
            update2(1,1,n,i,s);
        }
    }

    cout << ans;
}
