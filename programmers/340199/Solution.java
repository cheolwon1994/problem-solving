class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        while (true) {
            //그대로 넣기 시도
            if (wallet[0] >= bill[0] && wallet[1] >= bill[1]) break;
            //90도 돌려서 넣기 시도
            if (wallet[1] >= bill[0] && wallet[0] >= bill[1]) break;

            //접기 1회 추가
            answer++;

            //긴 쪽 접기
            if (bill[0] >= bill[1]) {
                bill[0] /= 2;
            } else {
                bill[1] /= 2;
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(new int[]{30, 15}, new int[]{26, 17})); // 1
        System.out.println(s.solution(new int[]{50, 50}, new int[]{100, 241})); // 4
    }
}
