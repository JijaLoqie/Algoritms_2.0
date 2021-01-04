#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

vector<long long> t;

void build(vector<long long> &a, int v, int lt, int rt) {
	if (lt == rt) {
		t[v] = a[lt];
	} else {
		int mid = (lt + rt) / 2;
		build(a, 2 * v, lt, mid);
		build(a, 2 * v + 1, mid + 1, rt);
		t[v] = t[v*2] + t[v*2+1];
	}
}
long long sum (int v, int lt, int rt, int l, int r) {
	if (l > r) {
		return 0;
	}
	if (l == lt && r == rt) {
		return t[v];
	}
	int mid = (lt + rt) / 2;
	return sum(v * 2, lt, mid, l, min(r, mid)) + sum(v * 2 + 1, mid + 1, rt, max(mid + 1, l), r);
}


void update(int v, int lt, int rt, int pos, int new_val) {
	if (lt == rt) {
		t[v] = new_val;
	} else {
		long long mid = (lt + rt) / 2;
		if (pos <= mid) {
			update(v*2, lt, mid, pos, new_val);
		} else {
			update(v*2+1, mid+1, rt, pos, new_val);
		}
		t[v] = t[v * 2] + t[v  * 2 + 1];
	}
}




int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	t.resize(n*4);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build(a, 1, 0, n-1);
	int q;
	cin >> q;
	while (q--) {
		string s;
		long long l, r;
		cin >> s >> l >> r;
		if (s == "s") {
			cout << sum(1, 0, n - 1, l-1, r-1) << " ";
		} else {
			update(1, 0, n-1, l - 1, r);
		}
	}

}
