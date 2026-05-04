#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

int n, U, V, p[maxn], d[maxn], dd[maxn];
int f[maxn], g[maxn];
vector <int> a[maxn];
void dfs(int u)
{
    d[u] = 1;
    if (u == V) dd[u] = 1;
    for (int v, i=0; i<a[u].size(); i++)
    {
        v = a[u][i];
        if (v == p[u]) continue;
        p[v] = u;
        dfs(v);
        if (dd[v] == 0) d[u] = max(d[u], d[v]+1);
        else dd[u] = 1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cin >> U >> V;
    dfs(U);
    vector <int> path;
    while (V!=0)
    {
        path.push_back(V);
        V = p[V];
    }
    f[-1] = 0;
    int m = path.size();
    for (int i=0; i<m; i++)
    {
        int v = path[i];
        f[i] = max(f[i-1], d[v] + i);
    }
    for (int i=m-1; ~i; i--)
    {
        int v = path[i];
        g[i] = max(g[i+1], d[v] + m-1-i);
    }
    int ans = 0;
    for (int i=0; i<m-1; i++)
        ans = max(min(f[i], g[i+1]), ans);
    cout << ans;
    return 0;
}
