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

int cnt[255];

int c[255];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    int n; cin >> n;
    string a,b; cin >> a >> b;
    for (int i = 0;i < a.size();++i){cnt[a[i]]++; c[b[i]]++;}

    if (cnt['a'] + cnt['b'] < c['c'] || cnt['a'] + cnt['c'] < c['b'] || cnt['b'] + cnt['c'] < c['a']) cout << -1;
    else{
        string s = "";
        for (int i = 0;i < a.size();++i){
            if (b[i] == 'a'){
                if (cnt['b'] > 0 && cnt['b'] - 1 + cnt['a'] >= c['c']){
                    s += 'b';
                    cnt['b']--; c['a']--;
                }else{
                    s += 'c';
                    cnt['c']--; c['a']--;
                }
            }else if (b[i] == 'b'){
                if (cnt['a'] > 0 && cnt['a'] - 1 + cnt['b'] >= c['c']){
                    s += 'a';
                    cnt['a']--; c['b']--;
                }else{
                    s += 'c';
                    cnt['c']--; c['b']--;
                }
            }else if (b[i] == 'c'){
                if (cnt['c'] > 0 && cnt['a'] - 1 + cnt['c'] >= c['b']){
                    s += 'a';
                    cnt['a']--; c['c']--;
                }else{
                    s += 'b';
                    cnt['b']--; c['c']--;
                }
            }
        }
        if (cnt['a'] < 0 || cnt['b'] < 0 || cnt['c'] < 0){cout << -1;}
        else{
          cout << s;
        }
    }

}
