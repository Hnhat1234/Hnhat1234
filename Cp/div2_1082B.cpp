#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string s; cin >> s;

		s = ' ' + s;

        int check = 1;
		if (n % 2 != 0){
			if (s[1] == 'b') check = 0;
			for (int i = 1;i <= n / 2;++i){
				if (s[2 * i] == s[2 * i + 1] && s[2 * i] != '?') check = 0; 
			}
		}else{
			for (int i = 1;i <= n / 2;++i){
				if (s[2 * i - 1] == s[2 * i] && s[2 * i] != '?') check = 0; 
			}
		}
		cout << (check == 1 ? "YES" : "NO") << '\n';
	}
}