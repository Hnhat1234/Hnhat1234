#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1005];

bool check[1005];
int main(){
  int n, m; cin >> n >> m;
  for (int i = 1;i <= m;++i){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }

  queue<int> q;
  q.push(1);

  vector<int> path;
  while (!q.empty()){
    int u = q.front();
    q.pop();

    if (check[u] == true) continue;
    check[u] = true;
    path.push_back(u);

    for (int v:adj[u]){
      q.push(v);
    }
  }
  for (int i = 0;i < int(path.size());++i){
    cout << path[i] << ' ';
  }
}
