import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    public int[] solution(int[][] edges) {
        int num = 0;
        HashMap<Integer, HashSet<Integer>> out = new HashMap<>();
        HashMap<Integer, HashSet<Integer>> in = new HashMap<>();
        TreeSet<Integer> ts = new TreeSet<>();
        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            num = Math.max(num, from);
            num = Math.max(num, to);
            ts.add(from);
            ts.add(to);
            out.computeIfAbsent(from, k -> new HashSet<>()).add(to);
            in.computeIfAbsent(to, k -> new HashSet<>()).add(from);
        }
        boolean[] visited = new boolean[num + 1];
        int donut = 0, stick = 0, eight = 0;

        // 추가된 Node: 받는거 0개 + 나가는거 여러개
        // 도넛: 각 Node당 나가는거 1개, 받는거 1개 + 순환
        // 막대: 각 Node랑 연결된게 없거나, 받는거 0게 + 나가는게 1개만 있는애부터 찾아서 쭉 시작
        // 8자: 나가는거 2개 + 받는거 2개를 찾으면 8자의 중심

        //1. 추가된 Node 찾기
        int addedNode = 0;
        for (Map.Entry<Integer, HashSet<Integer>> e : out.entrySet()) {
            // 받는거 0개, 나가는 개수 확인
            int node = e.getKey();
            if ((in.get(node) == null || in.get(node).isEmpty()) && out.get(node).size()>1) {
                addedNode = e.getKey();
                visited[addedNode] = true;
                break;
            }
        }

        //추가된 Node와 관련된 간선 지우기
        for(int a: out.get(addedNode)) {
            in.get(a).remove(addedNode);
        }

        for (int key: ts) {
            if (visited[key]) continue;
            HashSet<Integer> i = in.get(key);
            HashSet<Integer> o = out.get(key);

            // 2.막대 찾기
            //1개짜리 막대 찾기
            if ((i == null || i.isEmpty()) && (o == null || o.isEmpty())) {
                stick++;
                visited[key] = true;
                continue;
            }
            //2개 이상 막대 찾기: 받는거 0개 + 나가는거 1개
            if ((i == null || i.isEmpty()) && o.size() == 1) {
                stick++;
                int curr = key;
                while (true) {
                    visited[curr] = true;
                    if (out.get(curr) == null || out.get(curr).isEmpty()) break;
                    for (int a : out.get(curr)) {
                        curr = a;
                    }
                }
                continue;
            }
            //3. 8자 중심 찾기
            if ((i != null && i.size() == 2) && (o != null && o.size() == 2)) {
                eight++;
                Queue<Integer> q = new LinkedList<>();
                q.offer(key);
                visited[key] = true;

                while (!q.isEmpty()) {
                    int curr = q.poll();
                    HashSet<Integer> set = out.get(curr);
                    if(set != null) {
                        for (int a : set) {
                            if (!visited[a]) {
                                visited[a] = true;
                                q.offer(a);
                            }
                        }
                    }
                }
            }
        }
        //4. 도넛 찾기
        for (int key: ts) {
            if (visited[key]) continue;
            visited[key] = true;
            donut++;
            Queue<Integer> q = new LinkedList<>();
            q.offer(key);
            while (!q.isEmpty()) {
                int curr = q.poll();
                HashSet<Integer> set = out.get(curr);
                for (int a : set) {
                    if(!visited[a]) {
                        visited[a] = true;
                        q.offer(a);
                    }
                }
            }
        }

        return new int[]{addedNode, donut, stick, eight};
    }
}