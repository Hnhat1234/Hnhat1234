#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n + 5];
		int check[n + 5];
		for (int i = 0;i < n;++i){
			cin >> a[i];
			check[i] = 0;
		}
		
		int res = 0;
		for (int i = 0;i < n;++i){
            for (int j = i + 1;j < n;++j){
            	if (a[i] > a[j] && check[j] == 0){
            		res += 1;
            		check[j] = 1;
            	}
            }
		}
		cout << res << "\n";
	}
}