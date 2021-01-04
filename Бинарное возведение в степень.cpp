int binpow1 (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}

int binpow2 (int a, int n) {
	int ok = 0;
	if (n % 2)ok = 1;
	if (n == 0) {
		return 1;
	}
	int ans = a;
	n -= 1;
	while (n != 1) {
		if (n % 2 == 0) {
			ans *= ans;
			n /= 2;
		}
		else {
			ans *= a;
			n--;
		}
	}
	if (ok) {
		ans *= a;
	}
	return ans;
	
}
