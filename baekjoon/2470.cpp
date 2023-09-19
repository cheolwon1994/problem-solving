#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num,val;
    cin >> num;
    vector<int> v, answer;
    int l = 0, r = num - 1, sum = 0;
    for (int i = 0; i < num; i++) {
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    answer.push_back(v[0]);
    answer.push_back(v[num - 1]);
    sum = v[0] + v[num - 1];

    while (l < r) {
        int temp = v[l] + v[r];
        if (abs(temp) < abs(sum)) {
            sum = temp;
            answer[0] = v[l];
            answer[1] = v[r];
        }
        if (temp < 0) l++;
        else if (temp > 0) r--;
        else break;
    }
    cout << answer[0] << " " << answer[1];
    return 0;
}