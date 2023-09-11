#define MAXI 987654321
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

struct info {
    int idx, val;
};
struct cmp {
    bool operator()(info& a, info& b) {
        return a.val > b.val;
    }
};

int node, edge;
vector<info> v[20001];
int cost[20001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int startIdx, from, to, val;
    map<pair<int, int>, int> m;  //from,to,val
    cin >> node >> edge >> startIdx;
    for (int i = 0; i < edge; i++) {
        cin >> from >> to >> val;
        pair<int, int> key = make_pair(from, to);
        if (m.find(key) == m.end()) m[key] = val;
        else {
            if (m[key] >= val) m[key] = val;
        }
    }

    //간선 생성
    for (auto it = m.begin(); it != m.end(); it++) {
        pair<int,int> key = it->first;
        val = it->second;
        v[key.first].push_back({ key.second, val });
    }

    //초기화
    for (int i = 1; i <= node; i++)
        cost[i] = MAXI;

    cost[startIdx] = 0;
    priority_queue<info,vector<info>, cmp> pq;
    pq.push({ startIdx, 0 });

    while (!pq.empty()) {
        int cidx = pq.top().idx;
        int cv = pq.top().val;
        pq.pop();
        if (cv > cost[cidx]) continue;

        for (int i = 0; i < v[cidx].size(); i++) {
            int next = v[cidx][i].idx;
            int nv = cv + v[cidx][i].val;
            if (cost[next] > nv) {
                cost[next] = nv;
                pq.push({ next, nv });
            }
        }
    }

    for (int i = 1; i <= node; i++) {
        cost[i] == MAXI ? cout << "INF" : cout << cost[i];
        cout << '\n';
    }
    return 0;
}