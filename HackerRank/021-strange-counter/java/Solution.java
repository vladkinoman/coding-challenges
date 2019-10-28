import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the strangeCounter function below.
    static long strangeCounter(long t) {
        if (t < 1 || t > Math.pow(10, 12))
            throw new IllegalArgumentException();
        
        long tFirstSecOfCycle = 1;
        long value = 3;
        
        // Check the first t of the next cycle.
        while ((tFirstSecOfCycle + value) <= t) {
            tFirstSecOfCycle += value; 
            value = value * 2;
        }

        if (tFirstSecOfCycle == t) return value;
        value = value - (t - tFirstSecOfCycle);
        return value;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(
        	System.getenv("OUTPUT_PATH")));

        long t = scanner.nextLong();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        long result = strangeCounter(t);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
