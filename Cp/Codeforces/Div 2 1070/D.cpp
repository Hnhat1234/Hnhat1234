#include <bits/stdc++.h>
#define ll long long 

using namespace std;

ll mod = 998244353;

map<int, map<int, bool>> c;

ll a[200005];

bool cmp(pair<pair<int, int>, ll> a, pair<pair<int, int>, ll> b){
	if (a.second > b.second) return true;
	return false;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
	    vector<pair<pair<int, int>, ll>> adj;
	    for (int i = 1;i <= n;++i){
	    	cin >> a[i];
	    }
	    for (int i = 1;i <= m;++i){
	    	int u, v;
	    	cin >> u >> v;
	    	adj.push_back({{u, v}, a[u] + a[v]});
	    }
	    vector<map<ll, ll>> d(n + 5);
	    sort(adj.begin(), adj.end(), cmp);
	    ll ans = 0;
	    for (auto e:adj){
	    	int u = e.first.first;
	    	int v = e.first.second;
	    	ll s = e.second;

	    	int cur = d[v][s];
	    	cur = (cur + 1) % mod;
	    	d[u][a[v]] = (d[u][a[v]] + cur) % mod;
	    	ans = (ans + cur) % mod;

	    }
	    cout << ans << '\n';
	}
}