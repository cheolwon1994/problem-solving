#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1024][1024];
int sum[1025][1025];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, query, y1, y2, x1, x2;
	cin >> num >> query;
	for (int i = 0; i <= num; i++) {
		sum[0][i] = 0;
		sum[i][0] = 0;
	}

	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + arr[i][j];
		}

	while (query-- > 0) {
		cin >> y1 >> x1 >> y2 >> x2;
		y1--;
		y2--;
		x2--;
		x1--;

		cout << sum[y2 + 1][x2 + 1] + sum[y1][x1] - sum[y2 + 1][x1] - sum[y1][x2 + 1] << '\n';
	}
	return 0;
}