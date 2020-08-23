#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> v
vector<int> used;

void dfs(int u) {
    used[u] = 1;
    for (int i = 0; i < v[u].size(); i++) {
        if (used[v[u][i]] == 0) {
            dfs(v[u][i]);
            //there will be changes
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    v.resize(n);
    used.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[--a].push_back(--b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(i);
        }
    }
}