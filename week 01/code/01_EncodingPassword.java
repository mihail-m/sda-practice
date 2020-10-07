import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class EncodingPassword {
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
    }

    /**
     * Solution
     */

    private static String encode(String password) {
        StringBuilder encodedPassword = new StringBuilder();

        int cnt = 1;

        for (int i = 0; i < password.length() - 1; i++) {
            if (password.charAt(i) == password.charAt(i + 1)) {
                cnt++;
            } else {
                encodedPassword.append(cnt);
                encodedPassword.append(password.charAt(i));
                cnt = 1;
            }
        }

        encodedPassword.append(cnt);
        encodedPassword.append(password.charAt(password.length() - 1));

        return encodedPassword.toString();
    }

    public static void main(String[] args) {
        FastReader input = new FastReader();
        String password = input.next();
        System.out.println(encode(password));
    }
}
