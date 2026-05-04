#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		ll odd[n + 5], even[n + 5];
		ll prefix[n + 5];
		int len_odd = 0;
		int len_even = 0;

        odd[0] = 0;

		for (int i = 0;i < n;++i){
			ll x; cin >> x;
			if (x % 2 == 0){
				even[len_even++] = x;
			}else{
				odd[len_odd++] = x;
			}
		}
		sort(even, even + len_even, greater<ll>());
		sort(odd, odd + len_odd, greater<ll>());

		prefix[0] = even[0];
		for (int i = 1;i < len_even;++i){
			prefix[i] = prefix[i - 1] + even[i];
		}

		vector<ll> res(n + 5);
		for (int i = 1;i <= n;++i){
			if (i <= len_even + 1 && odd[0] != 0){
				res[i] = odd[0] + (i - 2 >= 0 ? prefix[i - 2] : 0ll);
			}else{
				res[i] = 0;
				if ((i - len_even) % 2 == 0 && (i - len_even) < len_odd && len_even > 0 && odd[0] != 0){
					res[i] = max(res[i], odd[0] + (len_even - 2 >= 0 ? prefix[len_even - 2] : 0ll));
				}
				if ((i - len_even) % 2 != 0 && odd[0] != 0){
					res[i] = max(res[i], odd[0] + (len_even - 1 >= 0 ? prefix[len_even - 1] : 0));
				}
			}
		}

		for (int i = 1;i <= n;++i){
			cout << res[i] << ' ';
		}
		cout << '\n';
		
	}
}