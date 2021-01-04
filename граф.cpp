#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<vector<int>> v;
vector<bool> used;

void dfs(int u) {
	used[u] = 1;
	for (int i = 0; i < v[u].size(); i++)
	{
		if (!used[v[u][i]]) {
			dfs(v[u][i]);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++)
	{
		if (!used[i]) {
			dfs(i);
		}
	}

}
