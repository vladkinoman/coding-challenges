import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the findDigits function below.
    static int findDigits(int n) {
        
        if (n <= 0 || n >= Math.pow(10, 9))
            throw new IllegalArgumentException();
        
        int numberOfDivisors = 0;
        int nRemaining = n;
        while (nRemaining != 0) {
            int d = nRemaining % 10; 
            if (d != 0 && n % d == 0) numberOfDivisors++;
            nRemaining /= 10;
        }

        return numberOfDivisors;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        
        if (t < 1 || t > 15)
            throw new IllegalArgumentException();

        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int result = findDigits(n);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
