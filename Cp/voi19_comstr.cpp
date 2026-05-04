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

int f[50], type[100005];

int cnt[30];

vector<int> pos[100005];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int m,m1,m2,r;
    cin >> m >> m1 >> m2 >> r;
    string s; cin >> s;
    s = ' ' + s;
    string a = "";
    a = ' ' + a;
    f[1] = m1; f[2] = m2;
    f[3] = f[1] + f[2];

    int dem = 3;
    while (a.size() < s.size()){
        if (a.size() == 1){
            for (int i = 1;i <= (m1 + m2);++i){a += s[i]; type[i] = i;}
        }else{
            int n = a.size() - 1;
            for (int i = 1;i <= min(m - n,f[dem - 1]);++i){a += s[i]; type[f[dem] + i] = type[i];}
            dem += 1;
            f[dem] = f[dem - 1] + f[dem - 2];
        }
    }
    int ans = 0;

    for (int i = (m1 + m2) + 1;i <= m;++i){
        pos[type[i]].push_back(i);
    }
    vector<int> arr;
    for (int i = 1;i <= (m1 + m2);++i){
        for (int x:pos[i]){
            cnt[s[x] - 'A']++;
        }
        int p = max_element(cnt,cnt + 26) - cnt;
        if (p + 'A' == s[i]){ans += pos[i].size() - cnt[p];}
        else{
            ans += pos[i].size() - cnt[s[i] - 'A'];
            arr.push_back(cnt[s[i] - 'A'] - cnt[p]);
        }
        memset(cnt,0,sizeof(cnt));
    }
    sort(arr.begin(),arr.end());
    for (int i = 0;i < min(r,(int)arr.size());++i){
        ans += arr[i];
    }
    cout << ans;
}
