class Solution {
public:
    struct info{
        char c;
        int dup;
    };
    struct cmp{
        bool operator()(info &a, info &b){
            if(a.dup == b.dup){
                return a.c > b.c;
            }
            return a.dup < b.dup;
        }
    };

    string frequencySort(string s) {
        map<char, int> m;
        for(char c: s){
            m[c]+=1;
        }
        priority_queue<info,vector<info>,cmp> pq;

        for(auto it = m.begin();it!=m.end();it++){
            pq.push({it->first, it->second});
        }
        string str = "";
        while(!pq.empty()){
            int t = pq.top().dup;
            char c = pq.top().c;
            for(int i=0;i<t;i++){
                str+=c;
            }
            pq.pop();
        }
        return str;
    }
};
