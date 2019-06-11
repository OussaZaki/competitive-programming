
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    public static final int MAXN = 1000000001;
    public static int[] blocks = new int[MAXN];
    
    public static void pre_process() {
        blocks[0] = 0;
        blocks[1] = 1;
        blocks[2] = 2;
        blocks[3] = 6;
        blocks[4] = 19;

        int theSum = 1;
        for (int i = 5; i < MAXN; i++) {
            theSum += blocks[i - 3];
            blocks[i] = 4 * blocks[i - 1] - 3 * blocks[i - 2] + theSum;
        }
    }
    
    public static void main(String[] args) {
        pre_process();
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
