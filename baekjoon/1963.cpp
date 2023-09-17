#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <queue>
#include <string>
using namespace std;
set<int> s;
bool isPrimary[10000];

void findPrimary(){
    for(int i=2;i<10000;i++)
        isPrimary[i] = true;
    for(int i=2;i<=sqrt(10000);i++){
        if(!isPrimary[i]) continue;
        for(int j=i+i;j<10000;j+=i)
            isPrimary[j] = false;
    }

    for(int i=1000;i<10000;i++){
        if(isPrimary[i])
            s.insert(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test,from,to;
    cin>>test;
    findPrimary();
    
    for(int t=0;t<test;t++){
        int answer = -1;
        cin>>from>>to;
        queue<pair<int, int> > q;
        map<int,int> m;
        q.push(make_pair(from,0));

        while(!q.empty()){
            int num = q.front().first;
            int cc = q.front().second;
            q.pop();
            if(num==to){
                answer = cc;
                break;
            }
            if(m[num]!=cc) continue;

            string str = to_string(num);
            for(int idx=0;idx<4;idx++){
                for(int j=0;j<10;j++){
                    if(idx==0 && j==0) continue;
                    string newStr = str;
                    newStr[idx] = j+'0';
                    int nextNum = stoi(newStr);
                    if(s.find(nextNum)!=s.end()){
                        if(m.find(nextNum)==m.end()){
                            m[nextNum] = cc+1;
                            q.push(make_pair(nextNum,cc+1));
                        }
                        else if(m[nextNum] > cc+1){
                            m[nextNum] = cc+1;
                            q.push(make_pair(nextNum,cc+1));
                        }

                    } 
                }
            }
        }
        if(answer == -1) cout<<"Impossible\n";
        else cout<<answer<<'\n';
    }

    return 0;
}