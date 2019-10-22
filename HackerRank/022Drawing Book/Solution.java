import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the pageCount function below.
     */
    static int pageCount(int n, int p) {
        if (n < 1 || n > Math.pow(10, 5))
            throw new IllegalArgumentException();
        if (p < 1 || p > n)
            throw new IllegalArgumentException();
        
        if (p == 1 || n == p ||
         (n % 2 != 0 && p == n - 1)) return 0;
        
        int leftCount = 1;
        int rightCount = 1;
    
        for (int i = 2; i < n; i += 2) {
            if (i == p || i+1 == p) break;
            else leftCount++;
        }

        for (int j = n; j > 1; j -= 2) {
            if (j == p || j-1 == p) break;
            else rightCount++;
        }

        return leftCount < rightCount ? leftCount : rightCount;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])*");

        int p = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])*");

        int result = pageCount(n, p);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
