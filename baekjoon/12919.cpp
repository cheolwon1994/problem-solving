#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string start, target;
bool finish;

void dfs(string str) {
    if (finish) return;
    int slen = str.size();
    if (slen == start.size()) {
        if(str == start) finish = true;
        return;
    }
    //뒤의 'A'를 지운다
    if (str[slen - 1] == 'A') dfs(str.substr(0, slen - 1));
    //앞의 B를 지우고 뒤집는다
    if (str[0] == 'B') {
        string temp = str.substr(1);
        reverse(temp.begin(), temp.end());
        dfs(temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    finish = false;
    cin >> start >> target;
    dfs(target);

    cout << finish;
    return 0;
}