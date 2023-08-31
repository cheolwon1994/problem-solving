#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, answer = 0;
	cin >> num;
	string s;
	cin >> s;

	for (char c : s) {
		int a = c - '0';
		answer += a;
	}
	cout << answer;
	return 0;
}