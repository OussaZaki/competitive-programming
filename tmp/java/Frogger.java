import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Frogger {

    int n, m, step;
    char[][] lanes = new char[24][52];
    char[][] possible = new char[24][52];
    char[][] next = new char[24][52];

    public static void main(String[] args) {
        Frogger frogger = new Frogger();
        frogger.solve();

    }

    public void solve() {
        FastScanner sc = new FastScanner();
        int T = sc.nextInt();
        int i, j;

        for (int test = 0; test < T; ++test) {
            int max_steps = sc.nextInt();
            n = sc.nextInt();
            m = sc.nextInt();
            String s = sc.nextToken();
            int end = s.indexOf('G');
            for (i = 2; i < n + 2; i++) {
                s = sc.nextToken();
                for (j = 1; j <= m; j++) {
                    lanes[i][j] = s.charAt(j - 1);
                    possible[i][j] = '.';
                    next[i][j] = '.';
                }
            }
            for (j = 1; j <= m; j++) {
                lanes[1][j] = 'O';
                lanes[n + 2][j] = 'O';
                possible[1][j] = '.';
                possible[n + 2][j] = '.';
                next[1][j] = '.';
                next[n + 2][j] = '.';
            }
            s = sc.nextToken();
            int start = s.indexOf('F');

            possible[n + 2][start + 1] = '*';
            step = 0;
            for (step = 1; step <= max_steps; step++) {
                // update lanes
                for (i = 0; i < n; i++) {
                    if ((i % 2) == 0) { // move right
                        for (j = m; j >= 1; j--) {
                            lanes[n - i + 1][j + 1] = lanes[n - i + 1][j];
                        }
                        lanes[n - i + 1][1] = lanes[n - i + 1][m + 1];
                    } else {  // move left
                        for (j = 1; j <= m; j++) {
                            lanes[n - i + 1][j - 1] = lanes[n - i + 1][j];
                        }
                        lanes[n - i + 1][m] = lanes[n - i + 1][0];
                    }
                }
                // update where we can go
                for (i = 1; i < n + 3; i++) {
                    for (j = 1; j <= m; j++) {
                        if (possible[i][j] == '*') {
                            if (lanes[i][j] == 'O') {
                                next[i][j] = '*';
                            }
                            if (lanes[i - 1][j] == 'O') {
                                next[i - 1][j] = '*';
                            }
                            if (lanes[i + 1][j] == 'O') {
                                next[i + 1][j] = '*';
                            }
                            if (lanes[i][j + 1] == 'O') {
                                next[i][j + 1] = '*';
                            }
                            if (lanes[i][j - 1] == 'O') {
                                next[i][j - 1] = '*';
                            }
                        }
                    }
                }
                for (i = 1; i < n + 3; i++) {
                    for (j = 1; j <= m; j++) {
                        possible[i][j] = next[i][j];
                        next[i][j] = '.';
                    }
                }
                if (possible[1][end + 1] == '*') {
                    break;
                }
            }

            if (possible[1][end + 1] == '*') {
                System.out.println("The minimum number of turns is " + step + ".");
            } else {
                System.out.println("The problem has no solution.");
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
