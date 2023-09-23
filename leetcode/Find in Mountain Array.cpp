/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
 
class Solution {
public:
    int bst(int l, int r, int target, MountainArray &mountainArr, bool isAsc){
        while(l <= r){
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);
            if(val == target) return mid;
            else if(val < target){
                if(isAsc) l = mid +1;
                else r = mid - 1;
            }
            else{
                if(isAsc) r = mid - 1;
                else l = mid + 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int l = 0, r = len - 1;
        int pivotIdx = 0;

        //1. find pivot
        while(l <= r){
            int mid = l + (r - l)/2;
            //can't compare mid's left
            if(mid == 0){
                l = mid + 1;
                continue;
            }
            //can't compare mid's right
            else if(mid == len - 1){
                r = mid - 1;
                continue;
            }
            int lv = mountainArr.get(mid - 1);
            int mv = mountainArr.get(mid);
            int rv = mountainArr.get(mid + 1);
            //compare mid's left and right, there are 3 shapes /, \, ^
            //shape ^
            if(lv < mv && mv > rv){
                pivotIdx = mid;
                break;
            }
            //shape /
            else if(lv < mv && mv < rv) l = mid + 1;
            //shape \,
            else r = mid - 1;
        }

        //check index 0 ~ pivotIdx if there is target
        int targetIdx = bst(0, pivotIdx, target, mountainArr, true);
        if(targetIdx != -1) return targetIdx;

        //check index pivotIdx+1~len-1 if there is target
        targetIdx = bst(pivotIdx + 1, len - 1, target, mountainArr, false);
        return targetIdx;
    }
};
