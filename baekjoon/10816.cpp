#include <iostream>
#include <algorithm>
using namespace std;
long long arr[500000];

int bst(int target, int len) {
	int l = 0, r = len - 1;
	int idx = len;

	while (l <= r) {
		int mid = l + (r - l) / 2;
		int val = arr[mid];
		if (target <= val) {
			idx = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return idx;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, target;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> target;
		cout << bst(target + 1, n) - bst(target, n) << " ";
	}
	return 0;
}