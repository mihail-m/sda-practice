import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class WatterSupplies {
    /**
     * Fast input
     */
    static class FastReader {
        private final BufferedReader br;
        private StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }

    /**
     * Solution
     */

    private static int water(int[] h, int l, int r) {
        return Math.min(h[l], h[r]) * (r - l);
    }

    private static int maxWater(int[] h) {
        int l = 0;
        int r = 0;

        int best = 0;

        while (r < h.length) {
            int cur = water(h, l, r);

            while (l < r && water(h,l + 1, r) > cur) {
                l++;
                cur = water(h, l, r);
            }

            best = Math.max(best, cur);
            r++;
        }

        return best;
    }

    public static void main(String[] args) {
        FastReader input = new FastReader();

        int n = input.nextInt();
        int[] h = new int[n];

        for (int i = 0; i < n; i++) {
            h[i] = input.nextInt();
        }

        System.out.println(maxWater(h));
    }
}
