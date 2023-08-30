#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	vector<string> answer;
	set<string> s;
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		s.insert(str);
	}

	for (int i = 0; i < m; i++) {
		cin >> str;
		if (s.find(str) != s.end())
			answer.push_back(str);
	}
	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (string ss : answer) {
		cout << ss << '\n';
	}
	return 0;
}