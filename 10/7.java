import java.util.*;

public class Main {

    // 노드의 개수(N)와 연산의 개수(M)
    // 노드의 개수는 최대 100,000개라고 가정
    public static int n, m;
    public static int[] parent = new int[100001]; // 부모 테이블 초기화

    // 특정 원소가 속한 집합을 찾기
    public static int findParent(int x) {
        // 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
        if (x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    // 두 원소가 속한 집합을 합치기
    public static void unionParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        // 부모 테이블상에서, 부모를 자기 자신으로 초기화
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // 각 연산을 하나씩 확인 
        for (int i = 0; i < m; i++) {
            int oper = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            // 합집합(Union) 연산인 경우
            if (oper == 0) {
                unionParent(a, b);
            }
            // 찾기(Find) 연산인 경우
            else if (oper == 1) {
                if (findParent(a) == findParent(b)) {
                    System.out.println("YES");
                }
                else {
                    System.out.println("NO");
                }
            }
        }
    }
}