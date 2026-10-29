import java.util.*;
import java.io.*;
import java.lang.*;
//
//class Info {
//    int right, below;
//
//    Info(int right, int below) {
//        this.right = right;
//        this.below = below;
//    }
//}

//
//class Solution {
//    public int solution(int[] mats, String[][] park) {
//        int answer = -1;
//        int row = park.length;
//        int col = park[0].length;
//        //정렬
//        Arrays.sort(mats);
//        //초기화
//        Info[][] avail_map = new Info[row][col];
//
//        for (int i = 0; i < row; i++) {
//            for (int j = 0; j < col; j++) {
//                String s = park[i][j];
//
//                //빈 공간X
//                if (!s.equals("-1")) {
//                    avail_map[i][j] = new Info(-1, -1);
//                    continue;
//                }
//
//                //오른쪽 확인
//                int r = 1;
//                for (int k = j + 1; k < col; k++) {
//                    if (park[i][k].equals("-1")) r++;
//                    else break;
//                }
//                //아래 확인
//                int b = 1;
//                for (int k = i + 1; k < row; k++) {
//                    if (park[k][j].equals("-1")) b++;
//                    else break;
//                }
//                avail_map[i][j] = new Info(r, b);
//            }
//        }
//
//
//        for(int i=0;i<row;i++){
//            for(int j=0;j<col;j++){
//                int ar = avail_map[i][j].right;
//                int ab = avail_map[i][j].below;
//                int m = Math.min(ar, ab);
//                if(m <= answer) continue;
//
//                boolean flag = true;
//                for(int k=i+1;k<i+m;k++){
//                    if(avail_map[k][j].right<m){
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag) {
//                    answer = Math.max(answer, m);
//                }
//            }
//        }
//
//        for(int i=mats.length-1;i>=0;i--) {
//            System.out.println(mats[i]);
//            if(mats[i]<=answer) {
//                answer = mats[i];
//                break;
//            }
//        }
//
//        System.out.println("======right=======");
//        for (int i = 0; i < row; i++) {
//            for (int j = 0; j < col; j++) {
//                System.out.print(avail_map[i][j].right + " ");
//            }
//            System.out.println();
//        }
//
//        System.out.println("======down=======");
//        for (int i = 0; i < row; i++) {
//            for (int j = 0; j < col; j++) {
//                System.out.print(avail_map[i][j].below + " ");
//            }
//            System.out.println();
//        }
//        return answer;
//    }
//
//    public static void main(String[] args) {
//        Solution s = new Solution();
////        System.out.println(s.solution(new int[]{5,3,2}, new int[]{26, 17})); // 1
////        System.out.println(s.solution(new int[]{50, 50}, new int[]{100, 241})); // 4
//    }
//}

class Solution {
    public int solution(int[] mats, String[][] park) {
        int answer = -1;
        int row = park.length;
        int col = park[0].length;

        //정렬
        Arrays.sort(mats);
        //초기화
        int[][] avail = new int[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                String s = park[i][j];

                //빈 공간X
                if (!s.equals("-1")) {
                    avail[i][j] = -1;
                    continue;
                }

                //오른쪽 확인
                int r = 1;
                for (int k = j + 1; k < col; k++) {
                    if (park[i][k].equals("-1")) r++;
                    else break;
                }
                avail_map[i][j] = r;
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int ar = avail[i][j];
                if(ar <= answer) continue;
                //밑으로 더 이상 설치할 수 없는 경우
                if(col-j+1<=ar) continue;

                boolean flag = true;
                for(int k=i+1;k<i+m;k++){
                    if(avail[k][j]<ar){
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    answer = Math.max(answer, ar);
                }
            }
        }

        for(int i=mats.length-1;i>=0;i--) {
            if(mats[i]<=answer) {
                answer = mats[i];
                break;
            }
        }

        System.out.println("======right=======");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print(avail_map[i][j].right + " ");
            }
            System.out.println();
        }

        System.out.println("======down=======");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print(avail_map[i][j].below + " ");
            }
            System.out.println();
        }
        return answer;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
//        System.out.println(s.solution(new int[]{5,3,2}, new int[]{26, 17})); // 1
//        System.out.println(s.solution(new int[]{50, 50}, new int[]{100, 241})); // 4
    }
}