#include <bits/stdc++.h>

using namespace std;

int p1[15][100005];

int p2[15][100005],sz2[15];

int sz[15],a[100005],pos[100005];
int main(){
    int n,m;cin >> n >> m;

    int dem=1;
    for (int k=0;k<m;++k){
        for (int j=1;j<=n;++j){cin >> a[j];pos[a[j]]=j;}
        if (k==0){
            for (int j=1;j<=n;++j){p1[0][j]=a[j];}
            sz[0]=n;
        }
        else{
            int tempdem=0;sz2[0]=1;
            for (int i=0;i<dem;++i){
                for (int j=2;j<=sz[i];){
                    while (pos[p1[i][j]]-pos[p1[i][j-1]]==1){
                        if (pos[p1[i][j]]-pos[p1[i][j-1]]!=1){
                            tempdem++;sz2[tempdem]=1;break;
                        }
                        p2[tempdem][sz2[tempdem]+1]=p1[i][j];p2[tempdem][sz2[tempdem]]=p1[i][j-1];
                        sz2[tempdem]++;
                        j+=1;
                    }
                    j+=1;
                }
            }
            for (int i=0;i<=tempdem;++i){
                for (int j=1;j<=sz2[i];++j){
                    p1[i][j]=p2[i][j];
                }
                sz[i]=sz2[i];
            }
            dem=tempdem+1;
        }
    }
    long long ans=0;
    for (int i=0;i<dem;++i){
        if (sz[i] > 1){
            ans+=1LL*(sz[i]*(sz[i]-1))/2;
        }
    }
    cout << ans+n;
}
