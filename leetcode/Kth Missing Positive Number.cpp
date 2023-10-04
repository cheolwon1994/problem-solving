class Solution {
public:
    int binary_search(int l, int r, vector<int>& arr, int k){
        if(l > r) return r;
        int mid = l + (r - l) / 2;
        int missCnt = arr[mid] - (mid + 1);
        if(missCnt < k) return binary_search(mid + 1, r, arr, k);
        else return binary_search(l, mid - 1, arr, k);
    }

    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1;
        int nearIdx = binary_search(l, r, arr, k);
        return nearIdx + k + 1;
    }
};