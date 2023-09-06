#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, q, val, sum = 0;
	long long answer = 0;
	map<int, int> m;	//나머지, 해당 나머지의 개수
	cin >> num >> q;
	m[0] = 1;
	for (int i = 0; i < num; i++) {
		cin >> val;
		sum = (val + sum) % q;
		m[sum] += 1;
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		val = it->second;
		if (val < 2) continue;
		answer += ((long long)val * (val - 1)) / 2;
	}

	cout << answer;
	return 0;
}