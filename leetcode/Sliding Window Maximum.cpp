class Solution {
public:
    struct info{
        int num, idx;
    };
    struct cmp{
        bool operator()(info &a, info &b){
            return a.num < b.num;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<info,vector<info>,cmp> pq;
        vector<int> answer;

        //1. insert first k
        for(int i=0;i<k;i++)
            pq.push({nums[i], i});

        //2. insert first biggest num;
        answer.push_back(pq.top().num);

        //3. push index number and find the biggest one
        for(int i=k;i<nums.size();i++){
            pq.push({nums[i],i});

            while(!pq.empty()){
                int cidx = pq.top().idx;
                if(i-k < cidx && cidx <= i){
                    answer.push_back({pq.top().num});
                    break;
                }
                pq.pop();
            }
        }

        return answer;    
    }
};
