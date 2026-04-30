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

ll a[100005], ll b[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("a.inp","r",stdin);

    int t;cin >> t;
    while (t--){


        int res = 0;

        int l = 0;

        int n; cin >> n;

        a[n + 1] = a[n + 2] = a[n + 3] = a[n + 4] = -1;

        for (int i = 1;i <= n;++i){cin >> a[i];}

        if (n <= 3){cout << ":(" << '\n';}
        else{
            for (int i = 1;i <= n - 3;){
                if (a[i] == 2 && a[i + 1] == 0 && a[i + 2] == 2 && a[i + 3] == 3){

                    res += 1;

                    int r = i + 4;

                    if (l <= 0){l = i - 1;}

                    while (r <= n - 3){
                        if (a[r] == 2 && a[r + 1] == 0 && a[r + 2] == 2 && a[r + 3] == 3){r += 4; res += 1;}
                        else{break;}
                    }

                    int temp = l;

                    while (l >= 1 && r <= n){
                        if (a[l - 1] == 2 && a[l] == 0 && a[r] == 2 && a[r + 1] == 3){res += 1; l -= 2; r += 2;}
                        else if (a[l] == 2 && a[r] == 0 && a[r + 1] == 2 && a[r + 2] == 3){res += 1; l -= 1; r += 3;}
                        else if (a[l - 2] == 2 && a[l - 1] == 0 && a[l] == 2 && a[r] == 3){res += 1; l -= 3; r += 1;}
                        else break;
                    }

                    i = r;

                    if (l == temp){l = 0;}
                }else{

                    int r = i + 1;

                    int temp = l;

                    while (l >= 1 && r <= n){
                        if (a[l - 1] == 2 && a[l] == 0 && a[r] == 2 && a[r + 1] == 3){res += 1; l -= 2; r += 2;}
                        else if (a[l] == 2 && a[r] == 0 && a[r + 1] == 2 && a[r + 2] == 3){res += 1; l -= 1; r += 3;}
                        else if (a[l - 2] == 2 && a[l - 1] == 0 && a[l] == 2 && a[r] == 3){res += 1; l -= 3; r += 1;}
                        else break;
                    }

                    i = r;

                    if (l == temp){l = 0;}
                }
            }

            if (res == 0){cout << ":(" << '\n';}
            else {cout << (res % 2 == 0 ? "Bemai" : "Bedao") << '\n';}
        }
    }
}
