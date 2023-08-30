#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a, b;
	int par[100001];
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		par[i] = -1;
		v[i].clear();
	}
	par[1] = 1;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (par[next] == -1) {
				par[next] = cidx;
				q.push(next);
			}
		}
	}
	for (int i = 2; i <= n; i++)
		cout << par[i] << '\n';
	return 0;
}