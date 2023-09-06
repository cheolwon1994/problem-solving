#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[100000];
int prefixSum[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, from, to;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	prefixSum[0] = 0;
	for (int i = 1; i <= n; i++)
		prefixSum[i] = prefixSum[i - 1] + arr[i - 1];

	while (m-- > 0) {
		cin >> from >> to;
		cout << prefixSum[to] - prefixSum[from - 1] << '\n';
	}
	return 0;
}