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

ll a[100005], pre[100005];

int cnt1[255], cnt2[255];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n,k; cin >> n >> k;
    string s,t;
    cin >> s >> t;
    for (int i = 1;i <= n;++i){cin >> a[i]; pre[i] = pre[i - 1] + a[i];}

    s = ' ' + s;
    t = ' ' + t;

    vector<pair<int,int>> p;

    vector<ll> b;

    int cur = 0;
    ll sum = 0;
    int l = 1; int check = 1;

    while (s[l] == t[l] && l <= n){l++;}
    for (int i = l;i <= n;++i){
        if (check && s[i] == t[i]){
            sum += a[i];
            cur = 1;
        }
        else if (check == 0 || s[i] != t[i]){
            if (l == 0){l = i;}
            if (cur == 1){b.push_back(sum); sum = 0; cur = 0;}

        cnt1[s[i]]++; cnt2[t[i]]++;

        int p1 = 1;
        for (int i = 'a';i <= 'z';++i){if (cnt1[i] != cnt2[i]){p1 = 0; break;}}
        check = p1;

        if (check){
            for (int i = 'a';i <= 'z';++i){cnt1[i] = cnt2[i] = 0;}
            p.push_back({l,i});
            l = 0;
        }
        }
    }

    ll ans = 0;
    int total = 1;
    for (int i = 0;i < p.size();++i){
        ans += pre[p[i].second] - pre[p[i].first - 1];
    }
    for (int i = 1;i < p.size();++i){
        if (p[i].first - p[i - 1].second != 1){total += 1;}
    }
    if (total <= k){cout << ans;}
    else{
        sort(b.begin(),b.end());
        for (int i = 0;i < total - k;++i){ans += b[i];}
        cout << ans;
    }
}
