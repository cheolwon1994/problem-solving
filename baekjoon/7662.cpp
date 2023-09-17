#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test, query, num;
    char c;
    cin >> test;

    for (int t = 0; t < test; t++) {
        cin >> query;
        priority_queue<int, vector<int>, greater<int>> smallest;
        priority_queue<int, vector<int>, less<int>> biggest;
        map<int, int> m;
        int len = 0;

        for (int k = 0; k < query; k++) {
            cin >> c >> num;
            if (c == 'I') {
                smallest.push(num);
                biggest.push(num);
                len++;
                m[num] += 1;
            }
            else {
                if (len == 0) continue;
                else {
                    int topNum = 0;
                    if (num == -1) {
                        while (true) {
                            topNum = smallest.top();
                            smallest.pop();
                            if (m[topNum] > 0) {
                                m[topNum]--;
                                break;
                            }
                        }
                    }
                    else {
                        while (true) {
                            topNum = biggest.top();
                            biggest.pop();
                            if (m[topNum] > 0) {
                                m[topNum]--;
                                break;
                            }
                        }
                    }
                    if (--len == 0) {
                        while (!smallest.empty()) smallest.pop();
                        while (!biggest.empty()) biggest.pop();
                    }
                }
            }
        }
        if (len == 0) cout << "EMPTY\n";
        else {
            while (true) {
                if (m[biggest.top()] > 0) break;
                biggest.pop();
            }
            while (true) {
                if (m[smallest.top()] > 0) break;
                smallest.pop();
            }
            cout << biggest.top() << " " << smallest.top() << '\n';
        }
    }
    
    return 0;
}