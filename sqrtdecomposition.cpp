#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int q = floor(sqrt(n));
    vector<int> v(n), t(q + 10);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        t[i/q] += v[i]; // code
    }

    int m;
    cin >> m;
    while (m--) {
        long long l, r, ans = 0;
        cin >> l >> r;
        for (int i = 0; i <= r;) {
            if (i%q == 0 && i + q - 1 <= r) {
                ans += t[i/q]; //code
                i += q;
            } else {
                ans += v[i];
                i++;
            }
        }
        cout << ans;
    }


}