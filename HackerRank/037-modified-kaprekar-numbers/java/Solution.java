import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    private static List<Long> digits(long n) {
        List<Long> digits = new ArrayList<>();
        while (n != 0) {
            digits.add(n % 10);
            n /= 10;
        }
        return digits;
    }
    // Complete the kaprekarNumbers function below.
    static void kaprekarNumbers(int p, int q) {
        if (p <= 0 || p >= 100000 || q <= p || q >= 100000)
            throw new IllegalArgumentException();
        
        int numberOfModifiedKaprekarNumbers = 0;
        for (int n = p; n <= q; n++) {
            List<Long> digits = digits((long) n);
            int d = digits.size();
            
            List<Long> digitsOfSquared = digits((long) n * n);
            int dOfSquared = digitsOfSquared.size();
            
            int i = 0;
            int r = 0;
            for (int mul = 1; i < d; i++, mul *= 10) {
                r += digitsOfSquared.get(i) * mul;
            }
            int l = 0;
            for (int mul = 1; i < dOfSquared; i++, mul *= 10) {
                l += digitsOfSquared.get(i) * mul;
            }

            if (r + l == n) {
                numberOfModifiedKaprekarNumbers++;
                System.out.print(n + " ");
            }
        }
        if (numberOfModifiedKaprekarNumbers == 0)
            System.out.println("INVALID RANGE");
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int p = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        kaprekarNumbers(p, q);

        scanner.close();
    }
}
