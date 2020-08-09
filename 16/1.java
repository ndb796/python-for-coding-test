import java.util.*;

public class Main {
	
    static int testCase, n, m;
    static int[][] arr = new int[20][20];
    static int[][] dp = new int[20][20];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 테스트 케이스(Test Case) 입력
        testCase = sc.nextInt();
        for (int tc = 0; tc < testCase; tc++) {
            // 금광 정보 입력
            n = sc.nextInt();
            m = sc.nextInt();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            // 다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    dp[i][j] = arr[i][j];
                }
            }
            // 다이나믹 프로그래밍 진행
            for (int j = 1; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    int leftUp, leftDown, left;
                    // 왼쪽 위에서 오는 경우
                    if (i == 0) leftUp = 0;
                    else leftUp = dp[i - 1][j - 1];
                    // 왼쪽 아래에서 오는 경우
                    if (i == n - 1) leftDown = 0;
                    else leftDown = dp[i + 1][j - 1];
                    // 왼쪽에서 오는 경우
                    left = dp[i][j - 1];
                    dp[i][j] = dp[i][j] + Math.max(leftUp, Math.max(leftDown, left));
                }
            }
            int result = 0;
            for (int i = 0; i < n; i++) {
                result = Math.max(result, dp[i][m - 1]);
            }
            System.out.println(result);
        }
    }
}