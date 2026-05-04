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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int a,b; cin >> a >> b;
        int n = max(sqrt(a),sqrt(b));
        int x = 0; int y = 0;
        for (int i = 2;i <= n;++i){
            int temp1 = 0; int temp2 = 0;
            while (a % i == 0){a/=i; temp1++;}
            while (b % i == 0){b/=i; temp2++;}
            if (temp1 > temp2){x += temp1 - temp2;}
            if (temp2 > temp1){y += temp2 - temp1;}
        }
        if (a != b && (a > 1 && b > 1)){x += 1; y += 1;}
        else if (a != b && a == 1){y += 1;}
        else if (a != b && b == 1){x += 1;}
        cout << max(x,y) << '\n';
    }
}
