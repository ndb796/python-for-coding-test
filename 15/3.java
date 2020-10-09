import java.util.*;

public class Main {

    public static void main(String[] args) {
        //  집의 개수(N)와 공유기의 개수(C)를 입력받기
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();

        // 전체 집의 좌표 정보를 입력받기
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }

        // 이진 탐색을 위해 정렬 수행
        Collections.sort(arr);

        int start = arr.get(1) - arr.get(0); // 집의 좌표 중에 가장 작은 값
        int end = arr.get(n - 1) - arr.get(0); // 집의 좌표 중에 가장 큰 값
        int result = 0;

        while (start <= end) {
            // mid는 가장 인접한 두 공유기 사이의 거리(Gap)을 의미
            int mid = (start + end) / 2;
            // 첫째 집에는 무조건 공유기를 설치한다고 가정
            int value = arr.get(0);
            int cnt = 1;
            // 현재의 mid 값을 이용해 공유기를 설치하기
            for (int i = 1; i < n; i++) { // 앞에서부터 차근차근 설치
                if (arr.get(i) >= value + mid) {
                    value = arr.get(i);
                    cnt += 1;
                }
            }
            // C개 이상의 공유기를 설치할 수 있는 경우, 거리를 증가시키기
            if (cnt >= c) {
                start = mid + 1;
                result = mid; // 최적의 결과를 저장
            }
            // C개 이상의 공유기를 설치할 수 없는 경우, 거리를 감소시키기
            else {
                end = mid - 1;
            }
        }
        System.out.println(result);
    }
}
