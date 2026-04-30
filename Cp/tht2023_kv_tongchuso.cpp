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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        string x; cin >> x;
        int s = 0;
        for (int i = 0;i < x.size();++i){
            s += (x[i] - '0');
        }
        if (s % 2 == 0){
            int mod = 0;
            string a = ""; string b = "";
            for (int i = 0;i < x.size();++i){
                if ((x[i] - '0') % 2 == 0){a += (char)((x[i] - '0')/2 + '0'); b += (char)((x[i] - '0')/2 + '0');}
                else{
                    if (mod == 0){
                        int temp = (x[i] - '0')/2;
                        a += (char)(temp + '0');
                        b += (char)(x[i] - '0' - temp + '0');
                        mod = 1;
                    }else{
                        int temp = (x[i] - '0')/2;
                        a += (char)(x[i] - '0' - temp + '0');
                        b += (char)(temp + '0');
                        mod = 0;
                    }
                }
            }
            while (a[0] == '0'){a.erase(a.begin());}
            while (b[0] == '0'){b.erase(b.begin());}
            cout << a << ' ' << b;
        }else{
            int pos = -1;
            for (int i = 1;i < x.size();++i){
                if (x[i] != '9' && x[i - 1] != '0'){pos = i; break;}
            }
            if (pos == -1){cout << -1;}
            else{
                string a = ""; string b = "";
                int r = x[pos] - '0' + 1;
                for (int i = x.size() - 1;i >= 0;--i){
                    b += '0';
                    if (i > pos){a += (char)x[i]; continue;}
                    if (x[i] - '0' >= r){
                        a += (char)(x[i] - r);
                        r = 0;
                    }else{
                        a += (char)(10 + x[i] - r);
                        r = 1;
                    }
                }
                b[pos] = x[pos] + 1;
                int suma = 0; int sumb = 0;
                for (int i = 0;i < x.size();++i){
                    suma += a[i] - '0';
                    sumb += b[i] - '0';
                }
                reverse(a.begin(),a.end());
                for (int i = 0;i < x.size();++i){
                    if (suma == sumb){break;}
                    if (a[i] == 0 && b[i] == 0){continue;}
                    int res = (suma - sumb)/2;
                    if (a[i] - '0' - res >= 0 && b[i] - '0' + res <= 9){
                        a[i] = a[i] - res;
                        b[i] = b[i] + res;
                        break;
                    }
                    suma = suma - (a[i] - '0') + b[i] - '0';
                    sumb = sumb - (b[i] - '0') + a[i] - '0';
                    swap(a[i],b[i]);
                }
                while (a[0] == '0'){a.erase(a.begin());}
                while (b[0] == '0'){b.erase(b.begin());}
                cout << a << ' ' << b;
            }
        }
        cout << '\n';
    }
}
