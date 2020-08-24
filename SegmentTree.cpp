#include <iostream>
#include <vector>

using namespace std;

vector<long long> t;
void build(vector<long long> &a, int v, int lt, int rt) {
    if (lt == rt) {
        t[v] = a[lt];
    } else {
        int mid = (lt + rt) / 2;
        build(a, 2*v, lt, mid);
        build(a, 2*v + 1, mid + 1, rt);
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

long long sum(int v,int lt, int rt, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == lt && r == rt) {
        return t[v];
    }
    int mid = (lt + rt) / 2;
    return sum(v*2, lt, mid, l, min(r, mid)) + sum(v*2 + 2, mid + 1, rt, max(l, mid + 1), r); //
}

void update(int v, int lt, int rt, int pos, int val) {
    if (lt == rt) {
        t[v] = val
    } else {
        int mid = (lt + rt) / 2;
        if (pos <= mid) {
            update(v*2, lt, mid, pos, val);
        } else {
            update(v*2 + 1, mid + 1, pos, val);
        }
        t[v] = t[v*2] + t[v*2 + 1]; //
    }
}





int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    t.resize(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(a, 1, 0, n - 1);
    int q;
    cin >> q;
    while (q--) {
        string s;
        long long l, r;
        cin >> s >> l >> r;
        if (s == 'sum') {
            cout << sum(1, 0, n - 1, l - 1, r - 1) << '\n';
        } else if (s == 'add') {
            update(1, 0, n - 1, l - 1, r);
        }
    }
}