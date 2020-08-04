import java.util.*;

public class Main {

    // 피보나치 함수(Fibonacci Function)을 재귀함수로 구현
    public static int fibo(int x) {
        if (x == 1 || x == 2) {
            return 1;
        }
        return fibo(x - 1) + fibo(x - 2);
    }

    public static void main(String[] args) {
        System.out.println(fibo(4));
    }

}