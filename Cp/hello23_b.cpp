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

int a[1000005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    int t;cin >> t;
    while (t--){


        int res = 0;

        int n; cin >> n;

        stack<int> st;

        for (int i = 1;i <= n;++i){
            cin >> a[i];
            st.push(a[i]);
            if (sz(st) <= 3) continue;
            else{
                int d = st.top(); st.pop();
                int c = st.top(); st.pop();
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (a == 2 && b == 0 && c == 2 && d == 3){res += 1;}
                else{
                    st.push(a); st.push(b); st.push(c); st.push(d);
                }
            }
        }

        if (res == 0){cout << ":(" << '\n';}
        else {cout << (res % 2 == 0 ? "Bemai" : "Bedao") << '\n';}
        }
}
