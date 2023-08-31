#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <sstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, cnt;
	string str, s, temp;
	cin >> num;
	while (num-- > 0) {
		cin >> str >> cnt >> s;
		s = s.substr(1, s.size() - 2);
		istringstream ss(s);

		deque<int> dq;
		while (getline(ss, temp, ',')) {
			dq.push_back(stoi(temp));
		}
		int idx = 0;
		string finish = "";
		for (int k = 0; k < str.size(); k++) {
			char c = str[k];
			if (c == 'R') {
				if (idx == 0) idx = dq.size() - 1;
				else idx = 0;
			}
			else {
				if (dq.empty()) {
					finish = "error";
					break;
				}
				if (idx == 0) dq.pop_front();
				else {
					dq.pop_back();
					idx = dq.size() - 1;
				}
			}
		}
		if (finish == "") {
			finish += "[";
			if (idx == 0) {
				for (int k = 0; k < dq.size(); k++) {
					if (k != dq.size() - 1) finish += (to_string(dq[k]) + ",");
					else finish += to_string(dq[k]);
				}
			}
			else {
				for (int k = dq.size() - 1; k >= 0; k--) {
					if(k!=0) finish += (to_string(dq[k]) + ",");
					else finish += to_string(dq[k]);
				}
			}
			
			finish += "]";
		}
		cout << finish << "\n";
	}

	return 0;
}