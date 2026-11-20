import java.util.*;
import java.io.*;
import java.lang.*;

// 번들 전체를 사거나, 안사거나(묶음이 가격)
class Solution {
    int answer;
    // int[] hints;

    public void dfs(int stage, int sum, int[] hints, int[][] cost, int[][] hint) {
        //최저값이 아니라면 return
        if(sum >= answer) return;
        if(stage > cost.length) {
            answer = sum;
            return;
        }

        int possessCurrentStageHint = hints[stage] >= cost[stage-1].length ? cost[stage-1].length-1 : hints[stage];

        //현재 스테이지를 깨고 힌트를 사지 않는다
        dfs(stage+1, sum + cost[stage-1][possessCurrentStageHint], hints, cost, hint);

        //힌트를 산다
        //힌트 비용: hint[stage-1][0]
        //마지막 단계는 힌트 구매가 없으니까 예외
        if(stage-1 < hint.length) {
            for (int i = 1; i < hint[stage - 1].length; i++) {
                int idx = hint[stage - 1][i];
                hints[idx]++;
            }
            dfs(stage + 1, sum + cost[stage - 1][possessCurrentStageHint] + hint[stage - 1][0], hints, cost, hint);
            for (int i = 1; i < hint[stage - 1].length; i++) {
                int idx = hint[stage - 1][i];
                hints[idx]--;
            }
        }
    }

    public int solution(int[][] cost, int[][] hint) {
        //init
        answer = Integer.MAX_VALUE;
        int len = cost.length;
        int[] hints = new int[len+1];     //보유한 각 스테이지의 힌트 수

        dfs(1, 0, hints, cost, hint);

        return answer;
    }
}