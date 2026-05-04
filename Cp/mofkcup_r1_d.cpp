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

ll ans[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;

    vector<int> a;
    vector<int> b;
    for (int i = 1;i <= 2 * n;++i){
        if (s[i] == '1'){b.push_back(i);}
        else{a.push_back(i);}
    }
    if (n == 1 && (s[1] == '0' || s[2] == '0')){cout << "NO"; return 0;}
    if (b.size() % 2){cout << "NO"; return 0;}

    int temp = n;
    for (int i = 0;i < b.size();i += 2){
        ans[b[i]] = ans[b[i + 1]] = temp--;
    }

    for (int i = 0;i < a.size();++i){
        if (i == a.size()/2){temp = 1;}
        if (i == 0){ans[a[i]] = temp; temp = 1;}
        else{
            ans[a[i]] = temp++;
        }
    }
    ll ma = 0;
    for (int i = a[0];i <= a[a.size() - 1];++i){
        ma = max(ma,ans[i]);
    }
    if (ma <= ans[a[0]]){cout << "NO"; return 0;}
    ll ma1 = 0;
    for (int i = a[a.size()/2 - 1];i <= a[a.size() - 2];++i){
        ma1 = max(ma1,ans[i]);
    }
    if (ma1 <= ans[a.size() - 2]){
        if (a[a.size() - 1] - a[a.size() - 2] == 1){swap(ans[a[a.size() - 1]],ans[a[a.size() - 2]]);}
        else{swap(ans[a[0]],ans[a[a.size()/2 - 1]]);}
    }

    cout << "YES" << '\n';
    for (int i = 1;i <= 2 * n;++i){cout << ans[i] << ' ';}
}
