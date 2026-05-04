/*
    www.youtube.com/YugiHackerChannel
    oj.vnoi.info/user/YugiHackerKhongCopCode
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn
using namespace std;
#define file1 "solution"
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i=11; i<=20; i++)
    {
        string Run = "giasach.exe <" + to_string(i) + ".inp >" + to_string(i) + ".out";
        system((Run).c_str());
    }

}
