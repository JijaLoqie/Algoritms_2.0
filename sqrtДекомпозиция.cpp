#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	int t = floor(sqrt(n));
	vector<long long> v(n), q(t+10);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		q[i/t] += v[i];
	}
	int m;
	cin >> m;
	while (m--) {
		long long l, r, ans = 0;
		cin >> l >> r;
		r--;
		l--;
		for (int i = l; i <= r;) {
			if (i % t == 0 && i + t - 1 <= r) {
				ans += q[i / t];
				i += t;
			} else {
				ans += v[i];
				i++;
			}
		}
		cout << ans << '\n';
	}
}
