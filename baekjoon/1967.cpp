#define MAXI 987654321
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
struct info {
	int idx, val;
};
vector<info> v[10001];
int dist[10001];
int answer, leafIdx, n;
vector<int> lgstLeaf;

void dijkstra(int start, bool findLgstRootToLeaf) {
	for (int i = 1; i <= n; i++)
		dist[i] = MAXI;
	vector<int> leaves;
	queue<info> q;
	q.push({ start ,0 });
	dist[start] = 0;
	int maxDist = 0;
	int idx = start;

	while (!q.empty()) {
		int cidx = q.front().idx;
		int cv = q.front().val;
		q.pop();
		if (cv > maxDist) {
			maxDist = cv;
			leaves.clear();
			leaves.push_back(cidx);
			answer = max(answer, maxDist);
		}
		else if (cv == maxDist) leaves.push_back(cidx);

		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val + cv;
			if (dist[next] > nv) {
				dist[next] = nv;
				q.push({ next, nv });
			}
		}
	}
	if (findLgstRootToLeaf) lgstLeaf = leaves;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, val, root = 1;
	answer = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> val;
		if (root == -1) root = a;
		v[a].push_back({ b,val });
		v[b].push_back({ a,val });
	}

	//1. root에서 각 leaf까지의 최대거리를 구한다
	dijkstra(root, true);

	//3. leafIdx부터 각 node까지의 최대거리를 구한다
	for (int i = 0; i < lgstLeaf.size(); i++) {
		dijkstra(lgstLeaf[i], false);
	}

	cout << answer;
	return 0;
}