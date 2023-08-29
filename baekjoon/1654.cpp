#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k, n, val;
    long long l = 1, r = 1, answer = 0;
    cin >> k >> n;
    vector<int> cable;
    for (int i = 0; i < k; i++) {
        cin >> val;
        r = max(r, (long long)val);
        cable.push_back(val);
    }

    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long cnt = 0;
        for (int i = 0; i < k; i++) 
            cnt += (cable[i] / mid);
        if (cnt >= n) {
            answer = max(answer, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << answer;
    return 0;
}
