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

int a[1000005];

int cnt[2];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    for (int i = 1;i <= n;++i){
        int x; cin >> x;
        a[i] = x % 2; cnt[a[i]]++;
    }
    if (cnt[1] != (n/2 + n%2)){cout << -1; return 0;}

    vector<int> pos1; vector<int> pos2;
    for (int i = 1;i <= n;++i){
        if (i % 2 == a[i]) continue;

        if (a[i] == 1){pos1.push_back(i);}
        else pos2.push_back(i);
    }

    long long ans = 0;
    for (int i = 0;i < pos1.size();++i){
        ans += abs(pos1[i] - pos2[i]);
    }

    cout << ans;
}
