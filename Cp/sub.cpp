#include <bits/stdc++.h>
#define ll long long 

using namespace std;

ll a[150005], b[150005], c[150005], d[150005];

vector<ll> m1[150005], m2[150005], m3[150005];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    int n1,n2,n3,n4; cin >> n1 >> n2 >> n3 >> n4;
    for (int i = 1;i <= n1;++i){cin >> a[i];}
    for (int i = 1;i <= n2;++i){cin >> b[i];}
    for (int i = 1;i <= n3;++i){cin >> c[i];}
    for (int i = 1;i <= n4;++i){cin >> d[i];}

    int s1,s2,s3; cin >> s1 >> s2 >> s3; 
    for (int i = 1;i <= s1;++i){
        int x,y; cin >> x >> y;
        m1[y].push_back(x);
    }
    for (int i = 1;i <= s2;++i){
    	int x,y; cin >> x >> y;
    	m2[y].push_back(x);
    }
    for (int i = 1;i <= s3;++i){
    	int x,y; cin >> x >> y;
    	m3[y].push_back(x);
    }
}