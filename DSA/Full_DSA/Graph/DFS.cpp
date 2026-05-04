#include <bits/stdc++.h>

using namespace std;

vector<int> adj[2000];

bool check[2000];

void dfs(int u){
  if (check[u] == true){
    return;
  }
  check[u] = true;
  cout << u << " ";
  for (int v:adj[u]){
    if (check[v] == true) continue;
    dfs(v);
  }
}
int main(){
  int n, m; cin >> n >> m;
  for (int i = 1;i <= m;++i){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }
  dfs(1);
}
