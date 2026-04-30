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

int cnt[3], snt[200005];

void sang(){
    for (int i = 2;i <= 200005;++i) snt[i] = 1;

    for (int i = 2;i <= sqrt(200005);++i){
        if (!snt[i]) continue;
        for (int j = i * i;j <= 200005;j += i){
            snt[j] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    int n; cin >> n;
    for (int i = 1;i <= n;++i){int x; cin >> x; cnt[x]++;}

    sang();
    if (cnt[1] == 0){cout << 1;}
    else if (cnt[2] == 0){
        int ans = 0;
        for (int i = 1;i <= n;++i) ans += snt[i];

        cout << ans;
    }
    else{
        int ans = 2;

        cnt[1]--; cnt[2]--;

        int cur = 3;
        while (cnt[2]--){
            cur += 2;
            ans += snt[cur];
        }

        while (cnt[1]--){
            cur += 1;
            ans += snt[cur];
        }
        cout << ans;
    }
}
