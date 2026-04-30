#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll f[1005];
int main(){
    int cur = 0;
    f[1] = 0; f[2] = 1;
    for (int i = 3;i <= 1000;++i){
        f[i] = f[i - 1] + f[i - 2];
        cout << f[i] << '\n';
    }
}
