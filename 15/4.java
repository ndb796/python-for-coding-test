import java.util.*;

class Solution {

    public int lowerBound(ArrayList<String> arr, String target, int start, int end) {
        while (start < end) {
            int mid = (start + end) / 2;
            // arr[mid]가 target보다 사전순으로 같거나 뒤에 있다면
            if (arr.get(mid).compareTo(target) >= 0) end = mid;
            else start = mid + 1;
        }
        return end;
    }

    public int upperBound(ArrayList<String> arr, String target, int start, int end) {
        while (start < end) {
            int mid = (start + end) / 2;
            // arr[mid]가 target보다 사전순으로 뒤에 있다면
            if (arr.get(mid).compareTo(target) > 0) end = mid;
            else start = mid + 1;
        }
        return end;
    }

    // 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
    public int countByRange(ArrayList<String> arr, String leftValue, String rightValue) {
        // 유의: lowerBound와 upperBound는 end 변수의 값을 배열의 길이로 설정
        int rightIndex = upperBound(arr, rightValue, 0, arr.size());
        int leftIndex = lowerBound(arr, leftValue, 0, arr.size());
        return rightIndex - leftIndex;
    }

    // 모든 단어들을 길이마다 나누어서 저장하기 위한 리스트
    public ArrayList<ArrayList<String>> arr = new ArrayList<ArrayList<String>>();
    // 모든 단어들을 길이마다 나누어서 뒤집어 저장하기 위한 리스트
    public ArrayList<ArrayList<String>> reversedArr = new ArrayList<ArrayList<String>>();

    public int[] solution(String[] words, String[] queries) {
        ArrayList<Integer> ans = new ArrayList<Integer>();

        // 단어의 길이는 10,000까지 가능
        for (int i = 0; i < 10001; i++) {
            arr.add(new ArrayList<String>());
            reversedArr.add(new ArrayList<String>());
        }

        // 모든 단어를 접미사 와일드카드 배열, 접두사 와일드카드 배열에 각각 삽입
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            arr.get(word.length()).add(word); // 단어를 삽입
            word = (new StringBuffer(word)).reverse().toString();
            reversedArr.get(word.length()).add(word); // 단어를 뒤집어서 삽입
        }

        // 이진 탐색을 수행하기 위해 각 단어 리스트 정렬 수행
        for (int i = 0; i < 10001; i++) {
            Collections.sort(arr.get(i));
            Collections.sort(reversedArr.get(i));
        }

        // 쿼리를 하나씩 확인하며 처리
        for (int i = 0; i < queries.length; i++) {
            String q = queries[i];
            int res = 0;
            if (q.charAt(0) != '?') { // 접미사에 와일드 카드가 붙은 경우
                res = countByRange(arr.get(q.length()), q.replaceAll("\\?", "a"), q.replaceAll("\\?", "z"));
            }
            else { // 접두사에 와일드 카드가 붙은 경우
                q = (new StringBuffer(q)).reverse().toString();
                res = countByRange(reversedArr.get(q.length()), q.replaceAll("\\?", "a"), q.replaceAll("\\?", "z")); 
            }
            // 검색된 단어의 개수를 저장
            ans.add(res);
        }

        // 배열로 바꾸어 반환
        int[] answer = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            answer[i] = ans.get(i);
        }
        return answer;
    }
}
