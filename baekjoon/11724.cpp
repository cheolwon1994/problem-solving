#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int flag[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, edge, answer = 0, a, b;
	vector<int> v[1001];
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= node; i++) {
		if (flag[i] == 0) {
			flag[i] = ++answer;
			queue<int> q;
			q.push(i);

			while (!q.empty()) {
				int cidx = q.front();
				q.pop();
				for (int k = 0; k < v[cidx].size(); k++) {
					int next = v[cidx][k];
					if (flag[next] == 0) {
						flag[next] = answer;
						q.push(next);
					}
				}
			}
		}
	}
	cout << answer;
	return 0;
}