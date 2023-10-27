#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
    int from, to, val;
};
struct cmp {
    bool operator()(info& a, info& b) {
        return a.val > b.val;
    }
};

int par[100001];

int findPar(int x) {
    if (par[x] == x) return x;
    return par[x] = findPar(par[x]);
}

void make_union(int a, int b) {
    int pa = findPar(a);
    int pb = findPar(b);

    if (pa < pb) par[pb] = pa;
    else if (pa > pb) par[pa] = pb;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int node, edge, from, to, val, answer = 0;
    priority_queue<info, vector<info>, cmp> pq;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        cin >> from >> to >> val;
        pq.push({ from, to, val });
    }
    //init
    for (int i = 1; i <= node; i++)
        par[i] = i;

    int conn = 0;
    while (!pq.empty() && conn < node-2) {
        info ii = pq.top();
        pq.pop();

        from = ii.from;
        to = ii.to;
        
        int pf = findPar(from);
        int pt = findPar(to);
        if (pf == pt) continue;
        conn++;
        answer += ii.val;
        make_union(from, to);
    }
    
    cout << answer;
    return 0;
}