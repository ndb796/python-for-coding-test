import java.util.*;

public class Main {

    public static int lowerBound(int[] arr, int target, int start, int end) {
        while (start < end) {
            int mid = (start + end) / 2;
            if (arr[mid] >= target) end = mid;
            else start = mid + 1;
        }
        return end;
    }

    public static int upperBound(int[] arr, int target, int start, int end) {
        while (start < end) {
            int mid = (start + end) / 2;
            if (arr[mid] > target) end = mid;
            else start = mid + 1;
        }
        return end;
    }

    // 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
    public static int countByRange(int[] arr, int leftValue, int rightValue) {
        // 유의: lowerBound와 upperBound는 end 변수의 값을 배열의 길이로 설정
        int rightIndex = upperBound(arr, rightValue, 0, arr.length);
        int leftIndex = lowerBound(arr, leftValue, 0, arr.length);
        return rightIndex - leftIndex;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // 데이터의 개수 N, 찾고자 하는 값 x 입력받기
        int n = sc.nextInt();
        int x = sc.nextInt();

        // 전체 데이터 입력받기
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        // 값이 [x, x] 범위에 있는 데이터의 개수 계산
        int cnt = countByRange(arr, x, x);
        
        // 값이 x인 원소가 존재하지 않는다면
        if (cnt == 0) System.out.println(-1);
        //  값이 x인 원소가 존재한다면
        else System.out.println(cnt);
    }
}
