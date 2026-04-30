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

const ll basehash = 31;
const ll modhash = 1000000003;

ll pw2[65];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    pw2[0] = 1;
    for (int i = 1;i <= 60;++i){pw2[i] = pw2[i - 1] * 2;}
    while (t--){
        ll a,s; cin >> a >> s;
        vector<int> bit1,bit2;
        map<int,int> check;
        ll temp = a;
        while (temp != 0){
            bit1.push_back(temp % 2);
            temp/=2;
        }
        ll sum = 0;
        for (int i = 0;i < bit1.size();++i){
            sum += pw2[i] * bit1[i];
            if (bit1[i] == 1){check[i] = 1;}
        }
        if (2 * sum - s > 0){cout << "No" << '\n';}
        else{
            int ans = 1;
            temp = s - sum * 2;
            while (temp != 0){
                bit2.push_back(temp % 2);
                temp/=2;
            }
            for (int i = 0;i < bit2.size();++i){
                if (check[i] && bit2[i] == 1){ans = 0; break;}
            }
            cout << (ans ? "Yes" : "No") << '\n';
        }
    }
}
