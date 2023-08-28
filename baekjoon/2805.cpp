#include <iostream>
#include <algorithm>
using namespace std;
int tree[1000000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, answer = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> tree[i];
	long long l = 0, r = 2000000000;

	while (l <= r) {
		long long mid = l + (r - l) / 2;
		long long treeSum = 0;
		for (int i = 0; i < n; i++) {
			int treeHeight = tree[i];
			if (treeHeight > mid) {
				treeSum += (treeHeight - mid);
			}
			if (treeSum >= m) break;
		}
		if (treeSum >= m) {
			answer = max(answer, (int)mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << answer;

	return 0;
}