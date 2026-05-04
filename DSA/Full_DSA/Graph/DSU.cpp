#include <bits/stdc++.h>

using namespace std;

int parent[2000], sz[2000];

void makeset(int v){
	parent[v] = v;
	sz[v] = 1;
}
int findset(int v){
	return (v == parent[v] ? v : parent[v] = findset(parent[v]));
}
void union_set(int u,int v){
	u = findset(u);
	v = findset(v);
	if (u != v){
		if (sz[u] < sz[v]) swap(u, v);
		parent[v] = u;
		sz[u] += sz[v];
	}
}

int main(){
	int n, m; cin >> n >> m;
	for (int i = 1;i <= n;++i){makeset(i);}
	for (int i = 1;i <= m;++i){
		int u, v; cin >> u >> v;
		union_set(u, v);
	}

	for (int i = 1;i <= n;++i) cout << findset(i);
}