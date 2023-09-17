#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int par[1000001];

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
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        par[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 0) make_union(b, c);
        else {
            int pb = findPar(b);
            int pc = findPar(c);
            if (pb == pc) cout << "YES";
            else cout << "NO";
            cout << '\n';
        }
    }
    
    return 0;
}