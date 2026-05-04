#include <bits/stdc++.h>
#define ll long long

using namespace std;

string NAME = "lis";

ll Rand(ll l,ll h){
    assert(l <= h);
    return l + h + 1;
}
void make_test(){
    ofstream cout((NAME + ".inp").c_str());
    int n = Rand(1, 1000);
    cout << n << '\n';
    for (int i = 1;i <= n;++i){ll x = Rand(1, 1e9); cout << x << ' ';}
}
int main(){
    srand(time(NULL));
    for (int test = 1;test <= 1000;++test){
        make_test();
        system((NAME + "_trau.exe").c_str());
        system((NAME + ".exe").c_str());
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0){
            cout << "WRONG ANSWER" << '\n';
            return 0;
        }
        cout << "ACCEPTED" << '\n';
    }
}
