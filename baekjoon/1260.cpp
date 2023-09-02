#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool arr[1001][1001];
bool visited[1001];
int node,startIdx;

void init(){
    for(int i=1;i<=node;i++)
        visited[i] = false;
}

void dfs(int cidx){
    cout<<cidx<<" ";
    for(int i=1;i<=node;i++){
        if(arr[cidx][i] && !visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }
}

void bfs(){
    init();
    cout<<'\n';
    queue<int> q;
    q.push(startIdx);
    visited[startIdx] = true;

    while(!q.empty()){
        int cidx = q.front();
        q.pop();
        cout<<cidx<<" ";
        for(int i=1;i<=node;i++){
            if(arr[cidx][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int a,b,edge;
    cin>>node>>edge>>startIdx;

    for(int i=0;i<edge;i++){
        cin>>a>>b;
        arr[a][b] =true;
        arr[b][a] =true;
    }
    init();
    visited[startIdx] = true;
    dfs(startIdx);
    bfs();

    return 0;
}