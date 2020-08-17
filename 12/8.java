import java.util.*;

class Permutation {
    private int n;
    private int r;
    private int[] now; // 현재 순열
    private ArrayList<ArrayList<Integer>> result; // 모든 순열

    public ArrayList<ArrayList<Integer>> getResult() {
        return result;
    }

    public Permutation(int n, int r) {
        this.n = n;
        this.r = r;
        this.now = new int[r];
        this.result = new ArrayList<ArrayList<Integer>>();
    }

    public void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void permutation(int[] arr, int depth) {
        // 현재 순열의 길이가 r일 때 결과 저장
        if (depth == r) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int i = 0; i < now.length; i++) {
                temp.add(now[i]);
            }
            result.add(temp);
            return;
        }
        for (int i = depth; i < n; i++) {
            swap(arr, i, depth);
            now[depth] = arr[depth];
            permutation(arr, depth + 1);
            swap(arr, i, depth);
        }
    }
}

class Solution {
    public int solution(int n, int[] weak, int[] dist) {
        // 길이를 2배로 늘려서 '원형'을 일자 형태로 변경
        ArrayList<Integer> weakList = new ArrayList<Integer>();
        for (int i = 0; i < weak.length; i++) {
            weakList.add(weak[i]);
        }
        for (int i = 0; i < weak.length; i++) {
            weakList.add(weak[i] + n);
        }
        // 투입할 친구 수의 최솟값을 찾아야 하므로 len(dist) + 1로 초기화
        int answer = dist.length + 1;
        // 친구 정보를 이용해 모든 순열 계산
        Permutation perm = new Permutation(dist.length, dist.length);
        perm.permutation(dist, 0);
        ArrayList<ArrayList<Integer>> distList = perm.getResult();
        // 0부터 length - 1까지의 위치를 각각 시작점으로 설정
        for (int start = 0; start < weak.length; start++) {
            // 친구를 나열하는 모든 경우 각각에 대하여 확인
            for (int i = 0; i < distList.size(); i++) {
                int cnt = 1; // 투입할 친구의 수
                // 해당 친구가 점검할 수 있는 마지막 위치
                int position = weakList.get(start) + distList.get(i).get(cnt - 1);
                // 시작점부터 모든 취약한 지점을 확인
                for (int index = start; index < start + weak.length; index++) {
                    // 점검할 수 있는 위치를 벗어나는 경우
                    if (position < weakList.get(index)) {
                        cnt += 1; // 새로운 친구를 투입
                        if (cnt > dist.length) { // 더 투입이 불가능하다면 종료
                            break;
                        }
                        position = weakList.get(index) + distList.get(i).get(cnt - 1);
                    }
                }
                answer = Math.min(answer, cnt); // 최솟값 계산
            }
        }
        if (answer > dist.length) {
            return -1;
        }
        return answer;
    }
}
