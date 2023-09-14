#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
struct info {
    int val, idx;
};
int arr[1000000];
int answer[1000000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num;
    cin >> num;
    stack<info> s;
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
        if (!s.empty()) {
            while (!s.empty()) {
                if (s.top().val < arr[i]) {
                    answer[s.top().idx] = arr[i];
                    s.pop();
                }
                else break;
            }
        }
        s.push({ arr[i],i });
    }
    while (!s.empty()) {
        answer[s.top().idx] = -1;
        s.pop();
    }
    for (int i = 0; i < num; i++) {
        cout << answer[i] << " ";
    }
    return 0;
}