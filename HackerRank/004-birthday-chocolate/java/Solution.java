import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the solve function below.
    static int solve(int[] s, int d, int m) {
        // constraints
        if(s.length < 1 || s.length > 100)
            throw new NegativeArraySizeException(
                    "Count of squares must be 1 <= n <=100");
        for (int i = 0; i < s.length; ++i)
            if(s[i]< 1 || s[i] > 5)
                throw new IllegalArgumentException(
                    "Numbers of chocolate bar must be 1 <= s[i] <=5");        
        if(d < 1 || d > 31)
            throw new IllegalArgumentException(
                "Birth day must be 1 <= m <= 31");
        if(m < 1 || m > 12)
            throw new IllegalArgumentException(
                "Birth month must be 1 <= m <= 12");


        int totalBarCount = 0;
        for (int i = 0; i < s.length; ++i)
        {
            int dSum = 0;
            int mCounter = 0;
            for (int j = i; j < s.length; ++j)
            {
                dSum += s[j];
                mCounter++;
                if(dSum == d && mCounter == m)
                {
                    totalBarCount++;
                    break;
                }
                if(dSum > d || mCounter > m)
                    break;
            }
        }

        return totalBarCount;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("out.txt"/*System.getenv("OUTPUT_PATH")*/));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] s = new int[n];

        String[] sItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int sItem = Integer.parseInt(sItems[i]);
            s[i] = sItem;
        }

        String[] dm = scanner.nextLine().split(" ");

        int d = Integer.parseInt(dm[0]);

        int m = Integer.parseInt(dm[1]);

        int result = solve(s, d, m);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
