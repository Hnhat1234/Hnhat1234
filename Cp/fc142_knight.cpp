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

int a[8] = {-2,-1,1,2,2,1,-1,-2};

int b[8] = {-1,-2,-2,-1,1,2,2,1};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 0;i < 8;++i){
        if (x1 + a[i] == x2 && y1 + b[i] == y2){cout << "Yes"; return 0;}
    }
    cout << "No";
}
