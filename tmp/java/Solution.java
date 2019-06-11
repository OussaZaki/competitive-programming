import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    public static int mod(int x) {
        return x % 1000000007;
    }

    public static int solve(String s){
        int len = s.length();
        int[][] nums = new int[len + 1][len + 1];
        int sum = 0;
        nums[0][0] = 1;

        for (int i = 0; i < len; ++i) {
            if(s.charAt(i) == '?') {
                sum = mod(sum * 2);
            }
            for (int j = 0; j <= i; ++j) {
                if (s.charAt(i) == '0' || s.charAt(i) == '?') {
                    nums[i + 1][j] = mod(nums[i + 1][j] + nums[i][j]);
                    sum = mod(sum + j * nums[i][j]);
                }

                if (s.charAt(i) == '1' || s.charAt(i) == '?') {
                    nums[i + 1][j + 1] = nums[i][j];
                }
            }
        }

        return sum;
    }
    
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        System.out.println(solve(sc.nextToken()));
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
