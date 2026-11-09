import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    //1. 각 배열의 가장 낮은 수보다 큰 최대공약수는 없다 -> 가장 작은 수를 구한다
    //2. 가장 작은 수의 공배수를 구해서 조건에 만족하는지 확인한다. 이때, 1은 생략한다

    public int check(int num, int[] arr) {
        for(int a: arr) {
            if(a%num == 0){
                return 0;
            }
        }
        return num;
    }

    public int checkList(List<Integer> li, int[] allCan, int[] allCannot) {
        int result = 0;
        for(int a : li) {
            if(a==1) continue;
            boolean avail = true;
            for(int num : allCan) {
                if(num%a !=0) {
                    avail =false;
                    break;
                }
            }
            if(!avail) continue;

            result = Math.max(result, check(a, allCannot));
        }
        return result;
    }


    public int solution(int[] arrayA, int[] arrayB) {
        int answer = 0;
        int miniA = 100000001;
        int miniB = 100000001;
        //1
        for(int a: arrayA){
            miniA = Math.min(miniA, a);
        }
        for(int b: arrayB){
            miniB = Math.min(miniB, b);
        }

        //miniA의 공배수로 구해본다
        List<Integer> aLi = new ArrayList<>();
        for(int i=1;i<=miniA/i;i++) {
            if(miniA%i == 0){
                aLi.add(i);
                if(i!=miniA/i) {
                    aLi.add(miniA/i);
                }
            }
        }
        Collections.sort(aLi);

        //miniB의 공배수로 구해본다
        List<Integer> bLi = new ArrayList<>();
        for(int i=1;i<=miniB/i;i++) {
            if(miniB%i == 0){
                bLi.add(i);
                if(i!=miniB/i) {
                    bLi.add(miniB/i);
                }
            }
        }
        Collections.sort(bLi);

        //2
        //A 공약수로 검사
        answer = Math.max(answer, checkList(aLi, arrayA, arrayB));

        //B 공약수로 검사
        answer = Math.max(answer, checkList(bLi, arrayB, arrayA));

        return answer;
    }
}