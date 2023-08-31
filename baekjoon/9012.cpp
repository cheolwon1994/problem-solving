#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num;
	string str;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> str;
		stack<char> s;
		string answer = "YES";
		for (int j = 0; j < str.size(); j++) {
			char c = str[j];
			if (c == '(') s.push(c);
			else {
				if (s.empty()) {
					answer = "NO";
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) answer = "NO";
		cout << answer << '\n';
	}
	
	return 0;
}