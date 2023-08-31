#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
int arr[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int answer = 0;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 1; i <= s1.size(); i++) {
		char c1 = s1[i - 1];
		for (int j = 1; j <= s2.size(); j++) {
			char c2 = s2[j - 1];
			if (c1 == c2) arr[i][j] = arr[i - 1][j - 1] + 1;
			else arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			answer = max(answer, arr[i][j]);
		}
	}

	cout << answer;
	return 0;
}