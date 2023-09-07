#define MAXI 987654321
#include <iostream>
#include <queue>
#include <map>
using namespace std;
int node,edge;
vector<pair<int,int> > v[20001];
int cost[20001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int startIdx,from,to,val;
    map<pair<int,int>, int> m;  //from,to,val
    cin>>node>>edge>>startIdx;
    for(int i=0;i<edge;i++){
        cin>>from>>to>>val;
        pair<int,int> key = make_pair(from,to);
        if(m.find(key)==m.end()) m[key] = val;
        else{
            if(m[key]>=val) m[key] = val;
        }
    }
    //간선 생성
    for(auto it = m.begin();it!=m.end();it++){
        pair<int,int> key = it->first;
        val = it->second;
        v[key.first].push_back(make_pair(key.second, val));
    }
    //초기화
    for(int i=1;i<=node;i++)
        cost[i] = MAXI;

    cost[startIdx] = 0;
    queue<pair<int, int> > q;   //idx, cost
    q.push(make_pair(startIdx,0));
    while(!q.empty()){
        int cidx = q.front().first;
        int cv = q.front().second;
        q.pop();
        for(int i=0;i<v[cidx].size();i++){
            int next = v[cidx][i].first;
            int nv = cv + v[cidx][i].second;
            if(cost[next] > nv){
                cost[next] = nv;
                q.push(make_pair(next, nv));
            }
        }
    }
    for(int i=1;i<=node;i++){
        cost[i] == MAXI ? cout<<"INF" : cout<<cost[i];
        cout<< '\n';
    }
    return 0;
}