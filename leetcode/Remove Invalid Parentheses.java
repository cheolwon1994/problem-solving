class Solution {
    int minRemoveCnt;
    HashSet<String> set;
    public void dfs(int idx, int removedCnt, StringBuilder sb, String s, Stack<Character> stack) {
        if(removedCnt > minRemoveCnt) return;
        if(idx == s.length()) {
            if(stack.isEmpty()) {
                if(removedCnt == minRemoveCnt) {
                    set.add(sb.toString());
                } else if (removedCnt < minRemoveCnt) {
                    set.clear();
                    set.add(sb.toString());
                    minRemoveCnt = removedCnt;
                }
            }
            return;
        }
        Character c = s.charAt(idx);
        if(c=='(') {
            //add stack
            stack.add(c);
            dfs(idx+1, removedCnt, sb.append(c), s, stack);
            stack.pop();
            sb.delete(sb.length()-1, sb.length());

            //remove
            dfs(idx+1, removedCnt+1, sb, s, stack);
        }else if(c==')'){
            if(stack.isEmpty()) {       //remove
                dfs(idx+1, removedCnt+1, sb, s, stack);
            } else {
                stack.pop();
                dfs(idx+1, removedCnt, sb.append(c), s, stack);
                stack.add('(');

                //remove
                sb.delete(sb.length()-1, sb.length());
                dfs(idx+1, removedCnt+1, sb, s, stack);
            }
        }else { //alphabet
            dfs(idx+1, removedCnt, sb.append(c), s, stack);
            //remove
            sb.delete(sb.length()-1, sb.length());
        }
    }

    public List<String> removeInvalidParentheses(String s) {
        //init
        minRemoveCnt = 30;      //25보다 큰 수
        set = new HashSet<>();
        dfs(0, 0, new StringBuilder(), s, new Stack<>());

        return new ArrayList<>(set);
    }
}