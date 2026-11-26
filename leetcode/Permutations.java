class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> answer = new ArrayList<>();
        Arrays.sort(nums);
        int len = nums.length;

        while(true) {
            answer.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));

            int pivot = len-2;
            for(;pivot>=0;pivot--) {
                // pivot 발견
                if(nums[pivot] < nums[pivot+1]) {
                    //nums[pivot] 보다 크면서 가장 작은 수
                    //뒤부터 탐색할경우 오름차순 정렬이기 때문에 뒤부터 검사
                    for(int j=len-1;j>pivot;j--){
                        if(nums[j] > nums[pivot]) {
                            //swap
                            int temp = nums[j];
                            nums[j] = nums[pivot];
                            nums[pivot] = temp;
                            break;
                        }
                    }
                    break;
                }
            }

            //pivot+1~len-1까지 정렬
            //reverse
            int l = pivot+1;
            int r = len-1;
            while(l<r) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
                r--;
            }
            if(pivot == -1) break;
        }

        return answer;
    }
}