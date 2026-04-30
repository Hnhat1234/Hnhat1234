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

ll prema[100005], arr[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    vector<pair<ll,ll>> a; vector<pair<ll,ll>> b;
    int n; ll s; cin >> n >> s;

    ll sum = 0; ll value = 0;

    ll ans = 0;
    for (int i = 1;i <= n;++i){
        ll w,v,c;
        cin >> w >> v >> c;
        if (c == 1){sum += w; value += v; a.push_back({w,v});}
        else{b.push_back({w,v});}
    }
    if (b.size() == 0){cout << value; return 0;}
    ans = value;
    sort(b.begin(),b.end());
    for (int i = 0;i < b.size();++i){
        arr[i + 1] = b[i].first;
        prema[i + 1] = max(prema[i],b[i].second);
    }

    int si = b.size();
    for (int i = 0;i < a.size();++i){
        int p = upper_bound(arr + 1,arr + 1 + si,s - (sum - a[i].first)) - arr;
        p--;
        if (p >= 1){ans = max(ans,value - a[i].second + prema[p]);}
    }

    cout << ans;
}
