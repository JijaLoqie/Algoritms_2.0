#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, long long>> t;
void build(vector<long long> &a, int v, int lt, int rt) {
    if (lt == rt) {
        t[v] = make_pair(a[lt], 1);
    } else {
        int mid = (lt + rt) / 2;
        build(a, 2*v, lt, mid);
        build(a, 2*v + 1, mid + 1, rt);
        int k;
        if (t[v*2].first > t[v*2+1].first) {
            k = t[v*2 + 1].second;
        } else if (t[v*2].first < t[v*2+1].first) {
            k = t[v*2].second;
        } else {
            k = t[v*2].second + t[v*2 + 1].second;
        }
        t[v] = make_pair(min(t[v*2], t[v*2 + 1]).first, k);
    }
}

pair<long long, long long> mina(int v, int lt, int rt, int l, int r) {
    if (l > r) {
        return make_pair(1e9, 1e9);
    }
    if (l == lt && r == rt) {
        return t[v];
    }
    int mid = (lt + rt) / 2;
    return min(mina(v*2, lt, mid, l, min(r, mid)), mina(v*2 + 1, mid + 1, rt, max(l, mid + 1), r)); //
}

void update(int v, int lt, int rt, int pos, long long val) {
    if (lt == rt) {
        int k;
        if (t[v*2].first > t[v*2+1].first) {
            k = t[v*2 + 1].second;
        } else if (t[v*2].first < t[v*2+1].first) {
            k = t[v*2].second;
        } else {
            k = t[v*2].second + t[v*2 + 1].second;
        }
        t[v] = make_pair(val, k);
    } else {
        int mid = (lt + rt) / 2;
        if (pos <= mid) {
            update(v*2, lt, mid, pos, val);
        } else {
            update(v*2 + 1, mid + 1, rt, pos, val);
        }
        int k;
        if (t[v*2].first > t[v*2+1].first) {
            k = t[v*2 + 1].second;
        } else if (t[v*2].first < t[v*2+1].first) {
            k = t[v*2].second;
        } else {
            k = t[v*2].second + t[v*2 + 1].second;
        }
        t[v] = make_pair(min(t[v*2], t[v*2 + 1]).first, k); //
    }
}





int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    t.resize(5 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(a, 1, 0, n - 1);
    while (q--) {
        int s;
        long long l, r;
        cin >> s >> l >> r;

        if (s == 2) {
            pair<long long, long long> d = mina(1, 0, n - 1, l, r - 1);
            cout << d.first << ' ' << d.second << '\n';
        } else if (s == 1) {
            update(1, 0, n - 1, l, r);
        }
    }
}