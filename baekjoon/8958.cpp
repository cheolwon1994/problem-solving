#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num;
	string s;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> s;
		int sum = 0;
		int correctCnt = 0;
		for (int j = 0; j < s.size(); j++) {
			char c = s[j];
			if (c == 'O') {
				sum += (++correctCnt);
			}
			else correctCnt = 0;
		}
		cout << sum << '\n';
	}

	return 0;
}