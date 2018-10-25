import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Java solution for Exploding CPU https://open.kattis.com/problems/cpu
 * @author Oussama Zaki <zaki.oussama@gmail.com>
 */
public class Cpu {

    static final int MAX_P = 2000001;
    static boolean[] isPrime = new boolean[MAX_P];

    public static void main(String[] args) {
        Cpu cpu = new Cpu();
        cpu.initPrimes();
        cpu.solve();
    }

    public void initPrimes() {
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i < MAX_P; ++i) {
            if (isPrime[i]) {
                for (int j = 2 * i; j < MAX_P; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    public void solve() {
        FastScanner sc = new FastScanner();
        int N = sc.nextInt();
        for (int test = 0; test < N; test++) {
            int xL = sc.nextInt();
            int xH = sc.nextInt();
            System.out.println(boom(xH) - boom(xL - 1));
        }
    }

    public int boom(long x) {
        int A, B, p1, p2, p3;
        int boomCount = 0;
        for (p1 = 2; p1 * p1 * p1 <= x; ++p1) {
            if (isPrime[p1]) {
                for (p2 = p1 + 1; p1 * p2 * p2 <= x; ++p2) {
                    if (isPrime[p2]) {
                        A = (p2 - p1) / (p1 - 1);
                        if (A * (p1 - 1) != p2 - p1) {
                            continue;
                        }
                        B = p1 - A;
                        p3 = A * p2 + B;
                        long prod = p1;
                        prod *= p2;
                        if (isPrime[p2] && p2 != p1) {
                            while (true) {
                                prod *= p3;
                                if (prod > x || !isPrime[p3]) {
                                    break;
                                } else {
                                    ++boomCount;
                                    p3 = A * p3 + B;
                                }
                            }
                        }
                    }
                }
            }
        }

        return boomCount;
    }

    public static class FastScanner {

        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}
