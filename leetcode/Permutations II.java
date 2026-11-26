class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> answer = new ArrayList<>();
        int len = nums.length;

        while(true) {
            answer.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));

            //pivot 찾기
            int pivot = len-2;
            for(;pivot>=0;pivot--) {
                if(nums[pivot] < nums[pivot+1]) {
                    for(int j=len-1;j>pivot;j--) {
                        if(nums[j] > nums[pivot]) {
                            int temp = nums[j];
                            nums[j] = nums[pivot];
                            nums[pivot] = temp;
                            break;
                        }
                    }

                    break;
                }
            }
            if(pivot == -1) break;
            //swap
            int l = pivot+1;
            int r = len-1;
            while(l<r && nums[l]!=nums[r]) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
                r--;
            }
        }

        return answer;
    }
}