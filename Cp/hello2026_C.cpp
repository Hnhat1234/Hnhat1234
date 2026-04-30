#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--){
        int n,m,k; cin>>n>>m>>k;
        int b=min(++m/3,min(k-1,n-k));
        cout<<min(n,1+2*b+(m-3*b)/2)<<"\n";
    }
}