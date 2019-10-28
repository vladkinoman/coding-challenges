import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    static int pageCount(int n, int p) {
        if (n < 1 || n > Math.pow(10, 5))
            throw new IllegalArgumentException();
        if (p < 1 || p > n)
            throw new IllegalArgumentException();
        
        // We won't iterate if our page is at the front/back of the book
        if (p == 1 || n == p ||
         (n % 2 != 0 && p == n - 1)) return 0;
        
        int leftCount = 1;
    
        for (int i = 2; i != p && i+1 != p; i += 2) {
            leftCount++;
        }

        int rightCount = 1;

        for (int j = n % 2 == 0 ? n - 1 : n - 2;
            j != p && j-1 != p; j -= 2) {
            rightCount++;
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
