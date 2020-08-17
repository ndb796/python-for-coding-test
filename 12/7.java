import java.util.*;

class Combination {
    private int n;
    private int r;
    private int[] now; // 현재 조합
    private ArrayList<ArrayList<Node>> result; // 모든 조합

    public ArrayList<ArrayList<Node>> getResult() {
        return result;
    }

    public Combination(int n, int r) {
        this.n = n;
        this.r = r;
        this.now = new int[r];
        this.result = new ArrayList<ArrayList<Node>>();
    }

    public void combination(ArrayList<Node> arr, int depth, int index, int target) {
        if (depth == r) {
            ArrayList<Node> temp = new ArrayList<>();
            for (int i = 0; i < now.length; i++) {
                temp.add(arr.get(now[i]));
            }
            result.add(temp);
            return;
        }
        if (target == n) return;
        now[index] = target;
        combination(arr, depth + 1, index + 1, target + 1);
        combination(arr, depth, index, target + 1);
    }
}

class Node {
    private int x;
    private int y;

    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }
}

public class Main {

    public static int n, m;
    public static int[][] arr = new int[50][50];
    public static ArrayList<Node> chicken = new ArrayList<>();
    public static ArrayList<Node> house = new ArrayList<>();

    public static int getSum(ArrayList<Node> candidates) {
        int result = 0;
          // 모든 집에 대하여
          for (int i = 0; i < house.size(); i++) {
              int hx = house.get(i).getX();
              int hy = house.get(i).getY();
              // 가장 가까운 치킨 집을 찾기
              int temp = (int) 1e9;
              for (int j = 0; j < candidates.size(); j++) {
                  int cx = candidates.get(j).getX();
                  int cy = candidates.get(j).getY();
                  temp = Math.min(temp, Math.abs(hx - cx) + Math.abs(hy - cy));
              }
              // 가장 가까운 치킨 집까지의 거리를 더하기
              result += temp;
          }
          // 치킨 거리의 합 반환
          return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                arr[r][c] = sc.nextInt();
                if (arr[r][c] == 1) house.add(new Node(r, c)); // 일반 집
                else if (arr[r][c] == 2) chicken.add(new Node(r, c)); // 치킨집
            }
        }

        // 모든 치킨 집 중에서 m개의 치킨 집을 뽑는 조합 계산
        Combination comb = new Combination(chicken.size(), m);
        comb.combination(chicken, 0, 0, 0);
        ArrayList<ArrayList<Node>> chickenList = comb.getResult();

        // 치킨 거리의 합의 최소를 찾아 출력
        int result = (int) 1e9;
        for (int i = 0; i < chickenList.size(); i++) {
            result = Math.min(result, getSum(chickenList.get(i)));
        }
        System.out.println(result);
    }
}
