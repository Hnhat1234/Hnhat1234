#include <bits/stdc++.h>
#define el cout<<'\n'
#define    f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
using namespace std;
const string NAME = "rabbit";

const int NTEST = 10;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}
void MakeTest(int iTest)
{
    ofstream cout((to_string(iTest) + ".inp").c_str());
    int n = Rand(1, 1e3); cout << n << '\n';
    for (int i = 1;i <= n;++i){
        long long x = Rand(1, 1e4);
        cout << x << ' ';
    }
}
int main()
{
    srand(time(NULL));
    for(int iTest = 11; iTest <= 20; iTest++)
    {
        MakeTest(iTest);
    }
    return 0;
}
