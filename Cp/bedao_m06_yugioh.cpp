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

int prime[1000005];

ll a[1000005];
void sang(){
    for (int i = 2;i <= 1000000;++i) prime[i] = 1;
    for (int i = 2;i <= 1000;++i){
        if (!prime[i]){continue;}
        for (int j = i * i;j <= 1000000;j += i){
            prime[j] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,x; cin >> n >> x;
    sang();

    int s = 0;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        if (a[i] <= 0) continue;
        if (prime[a[i]] && a[i] <= x){s++;}
    }

    int ans = 1e9; int cur = 0;
    for (int i = 1;i <= n;++i){
        if (i <= s){
            if (a[i] <= 0 || !prime[a[i]]){cur++;}
            else if (prime[a[i]] && a[i] > x){cur++;}
        }else{
           int r = i; int l = r - s + 1;
           if (a[l] <= 0 || !prime[a[l]]){cur--;}
           else if (prime[a[l]] && a[l] > x){cur--;}

           if (a[r] <= 0 || !prime[a[r]]){cur++;}
           else if (prime[a[i]] && a[r] > x){cur++;}
        }

        ans = min(ans,s - cur);
    }
    cout << ans << ' ' << s;
}
