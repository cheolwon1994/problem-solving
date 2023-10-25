#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int node, edge;
struct info {
    int from, to, val;
};
struct cmp {
    bool operator()(info& a, info& b) {
        return a.val > b.val;
    }
};
int par[10001];

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
    cin >> node >> edge;
    int from, to, val;
    long long sum = 0;
    priority_queue<info, vector<info>, cmp> pq;
    for (int i = 0; i < edge; i++) {
        cin >> from >> to >> val;
        pq.push({ from,to,val });
    }

    //init
    for (int i = 1; i <= node; i++)
        par[i] = i;

    while (!pq.empty()) {
        info ii = pq.top();
        pq.pop();
        int cf = ii.from;
        int ct = ii.to;
        int cv = ii.val;
        int pcf = findPar(cf);
        int pct = findPar(ct);
        if (pcf == pct) continue;
        make_union(pcf, pct);

        sum += (long long)cv;
    }

    cout << sum;
    return 0;
}