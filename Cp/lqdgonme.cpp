#include <bits/stdc++.h>

using namespace std;

int dp[1005];

int a[15][1005];

int b[1005];
int main(){
    int n,m;cin >> n >> m;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j){
            int x;cin >> x;
            if (i==1){b[j]=x;}
            a[i][x]=j;
        }
    }
    for (int i=1;i<=n;++i){
        dp[i]=1;
        for (int j=i-1;j>0;--j){
            int temp=0;
            for (int z=2;z<=m;++z){
                if (a[z][b[j]] < a[z][b[i]]){temp++;}
            }
            if (temp==m-1){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    cout << *max_element(dp+1,dp+1+n);
}
