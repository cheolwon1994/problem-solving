#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int len;
	cin >> len;

	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + len);

	int targetNums, target;
	cin >> targetNums;
	for (int i = 0; i < targetNums; i++) {
		cin >> target;
		int l = 0, r = len - 1;
		int found = 0;

		while (l <= r) {
			int mid = l + (r - l) / 2;
			int val = arr[mid];
			if (val == target) {
				found = 1;
				break;
			}
			else if (val < target) l = mid + 1;
			else r = mid - 1;
		}
		cout << found << "\n";
	}
	return 0;
}