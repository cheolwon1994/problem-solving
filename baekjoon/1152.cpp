#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s, str;
	getline(cin, s);
	istringstream ss(s);
	map<string, int> m;
	int answer = 0;

	while (getline(ss, str, ' ')) {
		if (str == "" || str[0] == ' ') continue;
		m[str] += 1;
	}

	for (auto it = m.begin(); it != m.end(); it++) 
		answer += (it->second);
	
	cout << answer;
	return 0;
}