#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num, val, answer = 0, zero = 0;
    cin >> num;
    priority_queue<int, vector<int>, less<int>> plus;
    priority_queue<int, vector<int>, greater<int>> minus;

    for (int i = 0; i < num; i++) {
        cin >> val;
        if (val == 0) {
            zero++;
            continue;
        }
        else if (val > 0) plus.push(val);
        else minus.push(val);
    }
    while (plus.size() > 1) {
        int mul = plus.top();
        int add = mul;
        plus.pop();
        mul *= plus.top();
        add += plus.top();
        plus.pop();
        answer += max(mul, add);
    }
    while (!plus.empty()) {
        answer += plus.top();
        plus.pop();
    }

    while (minus.size() > 1) {
        int mul = minus.top();
        int add = mul;
        minus.pop();
        mul *= minus.top();
        add += minus.top();
        minus.pop();
        answer += max(mul, add);
    }
    while (!minus.empty()) {
        if (zero == 0) answer += minus.top();
        else zero--;
        minus.pop();
    }

    cout << answer;
    return 0;
}