#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, val, answer = 0;
	cin >> num;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < num; i++) {
		cin >> val;
		pq.push(val);
	}
	while (pq.size()>1) {
		int sum = pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		answer += sum;
		pq.push(sum);
	}
	
	cout << answer;
	return 0;
}