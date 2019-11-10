import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the stones function below.
    static int[] stones(int n, int a, int b) {
        if (n < 1 || n > Math.pow(10, 3) || a < 1 || a > Math.pow(10, 3)
        || b < 1 || b > Math.pow(10, 3))
            throw new IllegalArgumentException();
        
        int min = Math.min(a, b);
        int max = Math.max(a, b);
        int minLast = (n - 1) * min;
        int maxLast = (n - 1) * max;
        int abs = 0;
        if (min == max) {
            abs = min;
        } else {
            abs = max - min;
        }

        List<Integer> l = new ArrayList<>();
        for (int i = minLast; i <= maxLast; i += abs) {
            l.add(i);
        }
        
        int[] result = new int [l.size()];
        for (int i = 0; i < l.size(); i++) {
            result[i] = l.get(i);
        }
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int T = scanner.nextInt();
        if (T < 1 || T > 10)
            throw new IllegalArgumentException();
        
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int TItr = 0; TItr < T; TItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int a = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int b = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] result = stones(n, a, b);

            for (int i = 0; i < result.length; i++) {
                bufferedWriter.write(String.valueOf(result[i]));

                if (i != result.length - 1) {
                    bufferedWriter.write(" ");
                }
            }

            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
