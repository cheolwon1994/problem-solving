#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct info {
    int idx, flagNum;
};
int node, edge;
int flag[20001];
vector<int> v[20001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test, a, b;
    cin >> test;
    for (int t = 0; t < test; t++) {
        cin >> node >> edge;
        //init
        for (int i = 1; i <= node; i++) {
            flag[i] = 0;
            v[i].clear();
        }

        for (int i = 0; i < edge; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        bool canDivide = true;
        for (int i = 1; i <= node; i++) {
            if (flag[i] == 0) {
                queue<info> q;
                q.push({ i,1 });
                flag[i] = 1;
                while (!q.empty()) {
                    info ii = q.front();
                    q.pop();
                    int cidx = ii.idx;
                    int cfn = ii.flagNum;
                    for (int k = 0; k < v[cidx].size(); k++) {
                        int next = v[cidx][k];
                        if (flag[next] == cfn) {
                            canDivide = false;
                            break;
                        }
                        else if (flag[next] == 0) {
                            flag[next] = 3 - cfn;
                            q.push({ next,3 - cfn });
                        }
                    }
                    if (!canDivide) break;
                }
            }
            if (!canDivide) break;
        }
        if (canDivide) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}