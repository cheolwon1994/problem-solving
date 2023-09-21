class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        vector<vector<int>> answer;
        //1. sort nums
        sort(nums.begin(), nums.end());
        int len = nums.size();
        //2. set 2 index by for clause
        for(int i=0;i<len-3;i++){
            for(int j=i+1;j<len-2;j++){
                //3. set 2 pointer
                int l = j+1;
                int r = len-1;

                while(l < r){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[l];
                    sum += nums[r];
                    if(sum == (long long)target){
                        s.insert({nums[i],nums[j],nums[l],nums[r]});
                    }
                    if(sum < target) l++;
                    else r--;
                }
            }
        }
        for(auto it = s.begin();it!=s.end();it++){
            answer.push_back(*it);
        }
        return answer;
    }
};