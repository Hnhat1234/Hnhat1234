#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(405);

int f(int u){
    if (!adj[u].size()) return 1;

    vector<int> a;
    for (auto v:adj[u]){
        a.push_back(f(v));
    }

    int ans = 0;

    sort(a.begin(),a.end(),greater<int>());

    for (int i = 0;i < a.size();++i){ans = max(ans,a[i] + i);}

    return ans;
}
int main(){
    int n; cin >> n;

    int s = 0;
    while (1){
        if (s == n - 1){break;}
        int i,m; cin >> i >> m;

        s += m;

        for (int j = 0;j < m;++j){
            int k; cin >> k;
            adj[i].push_back(k);
        }
    }
    cout << f(1);
}
