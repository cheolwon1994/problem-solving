#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, val;
    cin >> n;
    vector<int> card;
    for (int i = 0; i < n; i++) {
        cin >> val;
        card.push_back(val);
    }
    sort(card.begin(), card.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> val;
        int l = 0, r = card.size() - 1;
        int answer = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cv = card[mid];
            if (cv == val) {
                answer = 1;
                break;
            }
            else if (cv < val) l = mid + 1;
            else r = mid - 1;
        }
        cout << answer << ' ';
    }

    return 0;
}
