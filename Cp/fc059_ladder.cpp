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

int st[400005];

ll a[100005];

int x[100005],y[100005];

void build(int id,int l,int r){
    if (l == r){st[id] = y[l]; return;}
    int mid = (l + r)/2;
    build(id * 2,l,mid);
    build(id * 2 + 1,mid + 1,r);
    st[id] = max(st[id * 2],st[id * 2 + 1]);
}

int get(int id,int l,int r,int u,int v){
    if (l > v || r < u){return 0;}
    if (l >= u && r <= v){return st[id];}
    int mid = (l + r)/2;
    return max(get(id * 2,l,mid,u,v),get(id * 2 + 1,mid + 1,r,u,v));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int n,m; cin >> n >> m;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
    }

    int b = 1;
    for (int i = 1;i <= n;++i){
        if (i == 1){x[i] = 1; continue;}
        if (a[i] < a[i - 1]){b = i;}

        x[i] = b;
    }
    b = n;
    for (int i = n;i >= 1;--i){
        if (i == n){y[i] = n; continue;}
        if (a[i] < a[i + 1]){b = i;}

        y[i] = b;
    }

    build(1,1,n);
    while (m--){
        int l,r; cin >> l >> r;

        int p = upper_bound(x + 1 + l,x + r + 1,l) - x;
        p--;
        if (get(1,1,n,l,p) >= r){cout << "Yes" << '\n';}
        else cout << "No" << '\n';
    }
}
