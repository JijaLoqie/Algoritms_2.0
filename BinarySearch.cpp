#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void stop() {
    int x;
    cin >> x;
}


int bin_search(vector<int> &v, int x) {
    int l = 0, r = v.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (v[mid] < x) {
            l = mid + 1;
        } else if (v[mid] >= x) {
            r = mid;
        }
    }
    return r;
}



int main() {
    int n, a;
    cin >> n >> a;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << bin_search(v, a);
    stop();
}