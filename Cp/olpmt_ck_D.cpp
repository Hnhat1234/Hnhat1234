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

ll a,b;

ll dp[13][1000005], cnt[13][1000005];

ll tinh(ll x){
    ll s = 0;
    while (x != 0){
        s += x % 10;
        x/=10;
    }
    return s;
}

void sub1(ll a,ll b){
    ll ans = 0;
    for (int j = 0;j <= a;j += b){
        ans += tinh(j);
    }

    cout << ans << '\n';
}

void sub2(ll a,ll b){

    ll ans = 0;

    memset(dp,0,sizeof(dp)); memset(cnt,0,sizeof(cnt));
    for (int i = 1;i <= 13;++i){
      for (int d = 0;d <= 9;++d){
       if (i == 1){dp[i][d % b] = d; cnt[i][d % b] = 1; continue;}
        for (int mod = 0;mod < b;++mod){
            dp[i][(d + mod * 10) % b] += dp[i - 1][mod] + cnt[i - 1][mod] * d;
            cnt[i][(d + mod * 10) % b] += cnt[i - 1][mod];
        }
       }
    }

    string s = "";
    while (a != 0){s += (char)(a % 10); a/=10;}
    reverse(s.begin(),s.end());

    int n = sz(s);
    int sum = 0; int carry = 0;
    for (int i = 0;i < n;++i){
        if (i == 0){ans += dp[n - 1][0]; continue;}
        for (int j = 0;j < (s[i] - '0');++j){
            ans += dp[n - i - 2][(b * 1000000 - (carry * 10 + j)) % b] + cnt[n - i - 2][(b * 1000000 - (carry * 10 + j)) % b] * (sum + j);
        }
        carry = (10 * carry + s[i - 1]) % b;
        sum += s[i - 1] - 48;
    }

    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);

    for (int i = 1;i <= 2;++i){
        cin >> a >> b;
        sub2(a,b);
    }
}
