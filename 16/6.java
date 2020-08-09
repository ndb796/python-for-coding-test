import java.util.*;

public class Main {
	
    static String str1;
    static String str2;

    // 최소 편집 거리(Edit Distance) 계산을 위한 다이나믹 프로그래밍
    static int editDist(String str1, String str2) {
        int n = str1.length();
        int m = str2.length();

        // 다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
        int[][] dp = new int[n + 1][m + 1];

        // DP 테이블 초기 설정
        for (int i = 1; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = j;
        }

        // 최소 편집 거리 계산
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // 문자가 같다면, 왼쪽 위에 해당하는 수를 그대로 대입
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // 문자가 다르다면, 세 가지 경우 중에서 최솟값 찾기
                else { // 삽입(왼쪽), 삭제(위쪽), 교체(왼쪽 위) 중에서 최소 비용을 찾아 대입
                    dp[i][j] = 1 + Math.min(dp[i][j - 1], Math.min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }

        return dp[n][m];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str1 = sc.next();
        String str2 = sc.next();

        // 최소 편집 거리 출력
        System.out.println(editDist(str1, str2));
    }
}