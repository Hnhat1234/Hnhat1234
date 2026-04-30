#include <stdio.h>
main()
{
    freopen("lis.inp","r",stdin);
    freopen("lis.ans","w",stdout);
int n,a[1000],f[1000],max,m=0;
scanf("%d",&n);
for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
f[0]=1;
for(int i=1;i<n;i++)
  {
  max=0;
  for(int j=0;j<i;j++)
    if(a[i]>a[j]&&max<f[j])
      max=f[j];
  f[i]=max+1;
  }
for(int i=0;i<n;i++)
  if(f[i]>m)
    m=f[i];
printf("%d",m);
}
