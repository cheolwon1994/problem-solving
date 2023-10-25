#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
    int start, end;
};
struct cmp {
    bool operator()(info& a, info& b) {
        if (a.start == b.start) return a.end > b.end;
        return a.start > b.start;
    }
};
struct cmp2 {
    bool operator()(info& a, info& b) {
        if (a.end == b.end) return a.start < b.start;
        return a.end > b.end;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num, from, to, answer = 0;
    cin >> num;
    priority_queue<info, vector<info>, cmp> classPq;
    priority_queue<info, vector<info>, cmp2> usingClassroomPq;

    for (int i = 0; i < num; i++) {
        cin >> from >> to;
        classPq.push({ from, to });
    }

    while (!classPq.empty()) {
        info ii = classPq.top();
        classPq.pop();

        while (!usingClassroomPq.empty()) {
            if (usingClassroomPq.top().end > ii.start) break;
            else usingClassroomPq.pop();
        }
        usingClassroomPq.push({ ii.start, ii.end });
        int usingNum = usingClassroomPq.size();

        answer = max(answer, usingNum);
    }
    cout << answer;

    return 0;
}