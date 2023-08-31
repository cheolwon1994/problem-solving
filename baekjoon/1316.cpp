#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, answer = 0;
	string str;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> str;
		set<char> s;
		char pre = ' ';
		bool isGroup = true;

		for (int j = 0; j < str.size(); j++) {
			char c = str[j];
			if (c == pre) continue;
			else {
				if (s.find(c) != s.end()) {
					isGroup = false;
					break;
				}
				else {
					s.insert(c);
					pre = c;
				}
			}
		}
		if (isGroup) answer++;
	}

	cout << answer;
	return 0;
}