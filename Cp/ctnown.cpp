#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;


int prime[355];

ull f[355][75];

vector<int> p;

void sang(){
    for (int i=1;i<=350;++i){prime[i]=1;}
    prime[0]=prime[1]=0;
    for(int i=2;i*i<=350;++i){
     if(prime[i]){
         for(int j=i*2;j<=350;j+=i) prime[j] = 0;
     }
    }
    for(int i=2;i<=350;++i){if(prime[i]) p.push_back(i);}
}

void process(){
    for(int j=0;j<=70;++j) f[0][j] = 1;
    for(int i=1;i<=350;++i)
        for(int j=1;j<=70;++j){
            f[i][j]=max(f[i][j-1],f[i-1][j]);
            for(int z=p[j-1];i>=z;z*=p[j-1]){f[i][j]=max(f[i][j],f[i-z][j-1]*z);}
        }
}
int main() {
    sang();
    process();
    for (int i=1;i<=350;++i){
    cout << f[i][70] << '\n';
    }
}
