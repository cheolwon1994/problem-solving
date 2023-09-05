#define MAXI 200001
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int start, target, answer = 100000;
	cin >> start >> target;
	map<int, int> m;	//특정 위치까지, 걸린 시간
	queue<int> q;
	q.push(start);
	m[start] = 0;

	while (!q.empty()) {
		int cl = q.front();
		q.pop();
		int cc = m[cl];
		if (cc >= answer) continue;
		if (cl == target) {
			answer = min(answer, cc);
			continue;
		}
		vector<int> temp;

		if (cl > 0) temp.push_back(cl - 1);
		if (cl < target) temp.push_back(cl + 1);
		if (cl > 0 && 2 * cl <= MAXI) temp.push_back(2 * cl);

		for (int k = 0; k < temp.size(); k++) {
			int val = temp[k];
			if (m.find(val) == m.end() || m[val] > cc + 1) {
				m[val] = cc + 1;
				q.push(val);
			}
		}
	}

	cout << answer;
	return 0;
}