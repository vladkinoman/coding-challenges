import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the absolutePermutation function below.
    static int[] absolutePermutation(int n, int k) {
        int[] a = new int [n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        if      (k == 0) return a;
        else if (n % k != 0 || n / k % 2 != 0) {
            return new int [] {-1};
        }

        for (int i = 0; i < n; i += k) {
            for (int j = i + k, p = 0; p < k; p++, i++, j++) {
                int swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
        }

        return a;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        if (t < 1 || t > 10)
            throw new IllegalArgumentException();
        
        for (int tItr = 0; tItr < t; tItr++) {
            String[] nk = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nk[0]);
            if (n < 1 || n > Math.pow(10, 5))
                throw new IllegalArgumentException();
            
            int k = Integer.parseInt(nk[1]);
            if (k < 0 || k >= n)
                throw new IllegalArgumentException();
            
            int[] result = absolutePermutation(n, k);

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
