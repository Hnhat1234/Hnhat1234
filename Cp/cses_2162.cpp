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

int a[200005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n;cin >> n;

    unordered_set<int> s;
    for (int i = 1;i <= n;++i){
        s.insert(i);
    }

    auto p = s.begin();
    ++p;
    while (s.size()){
        int check = 0; int dem = 0;
        if (s.size() == 1){cout << *s.begin() << ' '; break;}
        a[dem++] = *p;
        ++p;
        if (p == s.end()){p = s.begin();}
    }
}
