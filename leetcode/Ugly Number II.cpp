class Solution {
public:

    int nthUglyNumber(int n) {
        set<int> s;
        int maxi = INT_MAX;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(1);
        s.insert(1);
        n--;

        while(!pq.empty()){
            if(n==0) break;
            int val = pq.top();
            pq.pop();
            n--;
            if(maxi/2 < val) continue;
            else{
                if(s.find(2 * val) == s.end()){
                    s.insert(2 * val);
                    pq.push(2 * val);
                }
            }

            if(maxi/3 < val) continue;
            else{
                if(s.find(3 * val) == s.end()){
                    s.insert(3 * val);
                    pq.push(3 * val);
                }
            }

            if(maxi/5 < val) continue;
            else{
                if(s.find(5 * val) == s.end()){
                    s.insert(5 * val);
                    pq.push(5 * val);
                }
            }
        }
        
        return pq.top();
    }
};