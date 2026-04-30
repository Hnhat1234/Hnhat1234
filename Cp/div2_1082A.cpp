#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int x, y; 
		cin >> x >> y;
		if (x == 1){cout << "NO";}
		else{
			if (x % 2 != 0) x = x - 3;

			int total = x / 2;
				
			if (y > 0){
				int x1 = y * 2;
				if (x - x1 < 0){
					cout << "NO";
				}else if (x - x1 == 0){
					cout << "YES";
				}else{
					cout << ((x - x1) % 3 == 0 ? "YES" : "NO");
				}
			}else if (y == 0){
				cout << (total % 3 == 0 ? "YES" : "NO");
			}else{
				int x1 = -y * 4;
				if (x - x1 < 0){
					cout << "NO";
				}else if (x - x1 == 0){
					cout << "YES";
				}else{
					cout << ((x - x1) % 3 == 0 ? "YES" : "NO");
				}
			}
		}
		cout << '\n';
	}
}