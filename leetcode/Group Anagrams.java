class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, Integer> stringToIdx = new HashMap<>();     //정렬된 string, index
        HashMap<Integer, List<String>> idxToString = new HashMap<>();   //index, 정렬되지 않은 string
        List<List<String>> answer = new ArrayList<>();

        int cnt = 0;
        for(String s: strs) {
            char[] arr = s.toCharArray();
            Arrays.sort(arr);

            String sortedStr = Arrays.toString(arr);
            Integer idx = stringToIdx.get(sortedStr);
            //신규
            if(idx == null) {
                stringToIdx.put(sortedStr, ++cnt);
                List<String> li = new ArrayList<>();
                li.add(s);      //원본 추가
                idxToString.put(cnt, li);
            } else {    //이미 있는 경우
                List<String> li = idxToString.get(idx);
                li.add(s);
                idxToString.put(idx, li);
            }
        }

        for(Map.Entry<Integer, List<String>> m : idxToString.entrySet()) {
            answer.add(m.getValue());
        }
        return answer;
    }
}