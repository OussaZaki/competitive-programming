
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Spiderman {

    static int[] d = new int[40];
    static int[][] minh = new int[40][1001];
    static char[][] move = new char[40][1001];

    public static void main(String[] args) {
        Spiderman spiderman = new Spiderman();
        spiderman.solve();
    }

    public void solve() {
        FastScanner sc = new FastScanner();
        int N = sc.nextInt();
        for (int test = 0; test < N; test++) {
            int M = sc.nextInt();
            int total = 0;
            for (int i = 0; i < M; i++) {
                d[i] = sc.nextInt();
                total += d[i];
            }

            for (int i = 0; i < M; ++i) {
                for (int j = 0; j <= total; ++j) {
                    minh[i][j] = Integer.MAX_VALUE;
                }
            }

            minh[M - 1][d[M - 1]] = d[M - 1];
            move[M - 1][d[M - 1]] = 'D';
            for (int i = M - 2; i >= 0; --i) {
                for (int h = 0; h <= total; ++h) {
                    if (minh[i + 1][h] != Integer.MAX_VALUE) {
                        // try climbingup from h-d[i]
                        if (h >= d[i]) {
                            if (minh[i][h - d[i]] > minh[i + 1][h]) {
                                minh[i][h - d[i]] = minh[i + 1][h];
                                move[i][h - d[i]] = 'U';
                            }
                        }
                        // try climbing down from h + d[i]
                        int newminh = Math.max(minh[i + 1][h], h + d[i]);
                        if (minh[i][h + d[i]] > newminh) {
                            minh[i][h + d[i]] = newminh;
                            move[i][h + d[i]] = 'D';
                        }
                    }
                }
            }
            if (minh[0][0] == Integer.MAX_VALUE) {
                System.out.println("IMPOSSIBLE");
            } else {
                int h = 0;
                for (int i = 0; i < M; ++i) {
                    System.out.print(move[i][h]);

                    if (move[i][h] == 'U') {
                        h += d[i];
                    } else {
                        h -= d[i];
                    }
                }
                System.out.println("");
            }
        }
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
