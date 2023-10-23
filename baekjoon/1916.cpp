#define MAXI 987654321
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
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
vector<info> v[1001];
int visit[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> node >> edge;
    int from, to, val, start, target;
    for (int i = 0; i < edge; i++) {
        cin >> from >> to >> val;
        v[from].push_back({ to, val });
    }
    cin >> start >> target;
    
    //init
    for (int i = 1; i <= node; i++)
        visit[i] = MAXI;
    visit[start] = 0;

    priority_queue<info, vector<info>, cmp> pq;
    pq.push({ start, 0 });
    while (!pq.empty()) {
        info ii = pq.top();
        pq.pop();
        int cidx = ii.idx;
        int cv = ii.val;
        if (visit[cidx] < cv) continue;
        for (int i = 0; i < v[cidx].size(); i++) {
            int next = v[cidx][i].idx;
            int nv = v[cidx][i].val + cv;
            if (visit[next] > nv) {
                visit[next] = nv;
                pq.push({ next, nv });
            }
        }
    }
    cout << visit[target];

    return 0;
}