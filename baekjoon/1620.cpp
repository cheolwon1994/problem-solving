#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	map<string, int> nameToIdx;
	map<int, string> idxToName;
	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		nameToIdx[str] = i;
		idxToName[i] = str;
	}

	for (int i = 0; i < m; i++) {
		cin >> str;
		char c = str[0];
		if ('A' <= c && c <= 'Z') 
			cout << nameToIdx[str] << '\n';
		else {
			int idx = stoi(str);
			cout << idxToName[idx] << '\n';
		}
	}

	return 0;
}