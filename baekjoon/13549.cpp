#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct info {
    int loc, move;
};
struct cmp {
    bool operator()(info& a, info& b) {
        return a.move > b.move;
    }
};
int n, target, answer;
int visited[100001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> target;
    int answer = 100001;

    if (n >= target) {
        cout << n - target;
        return 0;
    }

    priority_queue<info, vector<info>, cmp> pq;
    pq.push({ n,0 });
    for (int i = 1; i <= 100000; i++)
        visited[i] = 100001;
    visited[n] = 0;

    while (!pq.empty()) {
        int cl = pq.top().loc;
        int cm = pq.top().move;
        pq.pop();
        if (cl == target) {
            answer = min(answer, cm);
            break;
        }
        if (cl >= target) {
            answer = min(answer, cm + cl - target);
            continue;
        }

        //*2
        if (cl * 2 <= 100000 && visited[cl * 2] > cm) {
            visited[cl * 2] = cm;
            pq.push({ cl * 2, cm });
        }
        //+1
        if (cl + 1 <= 100000 && visited[cl + 1] > cm + 1) {
            visited[cl + 1] = cm + 1;
            pq.push({ cl + 1, cm + 1 });
        }
        //-1
        if (visited[cl - 1] > cm + 1) {
            visited[cl - 1] = cm + 1;
            pq.push({ cl - 1, cm + 1 });
        }
    }
    cout << answer;

    return 0;
}