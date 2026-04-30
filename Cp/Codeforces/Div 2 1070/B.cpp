#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string s; cin >> s;
		
		int res = 0;
		int counter = 0;
		for (int i = 0;i < n;++i){
			if (s[i] == '0'){
				counter++;
				res = max(res, counter);
			}else{
				counter = 0;
			}
		}
		int a = 0;
		int i = 0;
		while (s[i] == '0' && i < n){
			a++;
			i++;
		}
		i = n - 1;
        while (s[i] == '0' && i >= 0){
            a++;
            i--;
        }
		cout << max(res, a) << "\n";
	}
}