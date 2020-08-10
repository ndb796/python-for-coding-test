import java.util.*;

public class Main {

    public static int testCase, n, m;
    // 모든 노드에 대한 진입차수는 0으로 초기화
    public static int[] indegree = new int[501];
    // 각 노드에 연결된 간선 정보를 담기 위한 배열 초기화
    public static boolean[][] graph = new boolean[501][501];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        testCase = sc.nextInt();

        for (int tc = 0; tc < testCase; tc++) {
            Arrays.fill(indegree, 0);
            for (int i = 0; i < 501; i++) {
                Arrays.fill(graph[i], false);
            }

            n = sc.nextInt();
            // 작년 순위 정보 입력
            ArrayList<Integer> arrayList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                arrayList.add(x);
            }
            // 방향 그래프의 간선 정보 초기화
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    graph[arrayList.get(i)][arrayList.get(j)] = true;
                    indegree[arrayList.get(j)] += 1;
                }
            }

            // 올해 변경된 순위 정보 입력
            m = sc.nextInt();
            for (int i = 0; i < m; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                // 간선의 방향 뒤집기
                if (graph[a][b]) {
                    graph[a][b] = false;
                    graph[b][a] = true;
                    indegree[a] += 1;
                    indegree[b] -= 1;
                }
                else {
                    graph[a][b] = true;
                    graph[b][a] = false;
                    indegree[a] -= 1;
                    indegree[b] += 1;
                }
            }

            // 위상 정렬(Topology Sort) 시작
            ArrayList<Integer> result = new ArrayList<>(); // 알고리즘 수행 결과를 담을 리스트
            Queue<Integer> q = new LinkedList<>(); // 큐 라이브러리 사용

            // 처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
            for (int i = 1; i <= arrayList.size(); i++) {
                if (indegree[i] == 0) {
                    q.offer(i);
                }
            }

            boolean certain = true; // 위상 정렬 결과가 오직 하나인지의 여부
            boolean cycle = false; // 그래프 내 사이클이 존재하는지 여부

            // 정확히 노드의 개수만큼 반복
            for (int i = 0; i < n; i++) {
                // 큐가 비어 있다면 사이클이 발생했다는 의미
                if (q.size() == 0) {
                    cycle = true;
                    break;
                }
                // 큐의 원소가 2개 이상이라면 가능한 정렬 결과가 여러 개라는 의미
                if (q.size() >= 2) {
                    certain = false;
                    break;
                }
                // 큐에서 원소 꺼내기
                int now = q.poll();
                result.add(now);
                // 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
                for (int j = 1; j <= n; j++) {
                    if (graph[now][j]) {
                        indegree[j] -= 1;
                        // 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
                        if (indegree[j] == 0) {
                            q.offer(j);
                        }
                    }
                }
            }

            // 사이클이 발생하는 경우(일관성이 없는 경우)
            if (cycle) System.out.println("IMPOSSIBLE");
            // 위상 정렬 결과가 여러 개인 경우
            else if (!certain) System.out.println("?");
            // 위상 정렬을 수행한 결과 출력
            else {
                for (int i = 0; i < result.size(); i++) {
                    System.out.print(result.get(i) + " ");
                }
                System.out.println();
            }
        }
    }
}