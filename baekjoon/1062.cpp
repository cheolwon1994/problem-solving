#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
bool extraWord[50][26];
bool addedChar[26];
vector<char> words;
int answer, n;

void dfs(int idx, int remain) {
    if (remain == 0) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            bool avail = true;
            for (int j = 0; j < 26;j++) {
                if (extraWord[i][j] && !addedChar[j]) {
                    avail = false;
                    break;
                }
            }
            if (avail) cnt++;
        }
        answer = max(answer, cnt);
        return;
    }

    for (int i = idx; i < words.size(); i++) {
        addedChar[words[i] - 'a'] = true;
        dfs(i + 1, remain - 1);
        addedChar[words[i] - 'a'] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k;
    cin >> n >> k;
    //init
    set<char> s;
    answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++)
            extraWord[i][j] = false;
    }
    for (int j = 0; j < 26; j++)
        addedChar[j] = false;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (char c : str) {
            if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') continue;
            s.insert(c);
            extraWord[i][c - 'a'] = true;
        }
    }
    if (k < 5) {
        cout << answer;
        return 0;
    }
    else if (k - 5 >= s.size()) {
        cout << n;
        return 0;
    }
    for (auto it = s.begin(); it != s.end(); it++)
        words.push_back(*it);
    dfs(0, k - 5);

    cout << answer;
    return 0;
}