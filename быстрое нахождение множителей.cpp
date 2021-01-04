#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> v;




int main() {
	long long n, k;
	cin >> n >> k;
	for (long long i = 1; i * i <= n; i++) {
		if (n%i==0) {
			v.push_back(i);
			if (i*i != n && n%(n/i) == 0) {
				v.push_back(n/i);
			}
		}
	}
	sort(v.begin(), v.end());
	if (k > v.size()) {
		cout << -1 << "\n";
	} else {
		cout << v[k-1] << "\n";
	}
}
