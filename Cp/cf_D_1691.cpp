#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 200005
using namespace std;
int t, n, a[maxn], l[maxn], r[maxn];
long long s[2][maxn], ma[2][20][maxn];
long long get(int t, int l, int r)
{
    int k = log2(r-l+1);
    return max(ma[t][k][l], ma[t][k][r-(1<<k)+1]);
}
void solve()
{
    cin >> n;
    f1 (i, n) cin >> a[i], s[0][i] = s[0][i-1] + a[i];
    for (int i=n; i; i--) s[1][i] = s[1][i+1] + a[i];
    a[0] = 2e9;
    stack <int> st;
    st.push(0);
    f1 (i, n)
    {
        while (st.size() && a[i] >= a[st.top()]) st.pop();
        l[i] = st.top() + 1;
        st.push(i);
    }
    while (st.size()) st.pop();
    st.push(n+1);
    a[n+1] = 2e9;
    for (int i=n; i; i--)
    {
        while (st.size() && a[i] >= a[st.top()]) st.pop();
        r[i] = st.top() - 1;
        st.push(i);
    }
    f1 (i, n) ma[0][0][i] = s[0][i], ma[1][0][i] = s[1][i];
    for (int i=1; 1 << i <= n; i++)
    {
        for (int j=1; j+(1<<i)-1 <=n; j++)
        {
            ma[0][i][j] = max(ma[0][i-1][j], ma[0][i-1][j + (1 << (i-1))]);
            ma[1][i][j] = max(ma[1][i-1][j], ma[1][i-1][j + (1 << (i-1))]);
        }
    }
    bool ok = 1;
    f1 (i, n)
    {
        long long L = get(1, l[i], i), R = get(0, i, r[i]);
        if (L - s[1][i+1] > a[i] || R - s[0][i-1] > a[i]) ok = 0;
        //cout << i << ' ' << l[i] << ' ' << r[i] << ' '  << L << ' ' << R; el;
    }
    if (ok) cout << "YES";
    else cout << "NO";
    el;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
}
