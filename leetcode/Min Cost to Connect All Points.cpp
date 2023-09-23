class Solution {
public:
    struct info{
        int from, to, val;
    };
    struct cmp{
        bool operator()(info &a, info &b){
            return a.val > b.val;
        }
    };
    int par[1000];

    int findPar(int x){
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }

    void make_union(int a, int b){
        int pa = findPar(a);
        int pb = findPar(b);
        if(pa < pb) par[pb] = pa;
        else if(pa > pb) par[pa] = pb;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int answer = 0;
        //init
        int num = points.size();
        priority_queue<info,vector<info>,cmp> pq;
        for(int i=0;i<num;i++)
            par[i] = i;
        for(int i=0;i<num-1;i++){
            for(int j=i+1;j<num;j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({i,j,dist});
            }
        }

        while(!pq.empty()){
            int from = pq.top().from;
            int to = pq.top().to;
            int val = pq.top().val;
            pq.pop();
            int pf = findPar(from);
            int pt = findPar(to);
            if(pf == pt) continue;
            answer += val;
            make_union(pf, pt);
        }

        return answer;
    }
};