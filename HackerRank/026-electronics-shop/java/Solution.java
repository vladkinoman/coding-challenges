import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the getMoneySpent function below.
     */
    static int getMoneySpent(int[] keyboards, int[] drives, int b) {
        int n = keyboards.length;
        int m = drives.length;
        // Constraints.
        if (n < 1 || n > 1000 || m < 1 || m > 1000)
            throw new IllegalArgumentException();
        if (b < 1 || b > Math.pow(10, 6))
            throw new IllegalArgumentException();
        for (int i = 0; i < n; i++)
            if (keyboards[i] < 1 || keyboards[i] > Math.pow(10, 6))
                throw new IllegalArgumentException();
        for (int i = 0; i < m; i++)
            if (drives[i] < 1 || drives[i] > Math.pow(10, 6))
                throw new IllegalArgumentException();
        
        int maxSum = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = keyboards[i] + drives[j];
                if (sum <= b && sum > maxSum)
                    maxSum = sum;
            }
        }

        return maxSum;        
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] bnm = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])*");

        int b = Integer.parseInt(bnm[0]);

        int n = Integer.parseInt(bnm[1]);

        int m = Integer.parseInt(bnm[2]);

        int[] keyboards = new int[n];

        String[] keyboardsItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])*");

        for (int keyboardsItr = 0; keyboardsItr < n; keyboardsItr++) {
            int keyboardsItem = Integer.parseInt(keyboardsItems[keyboardsItr]);
            keyboards[keyboardsItr] = keyboardsItem;
        }

        int[] drives = new int[m];

        String[] drivesItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])*");

        for (int drivesItr = 0; drivesItr < m; drivesItr++) {
            int drivesItem = Integer.parseInt(drivesItems[drivesItr]);
            drives[drivesItr] = drivesItem;
        }

        /*
         * The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
         */

        int moneySpent = getMoneySpent(keyboards, drives, b);

        bufferedWriter.write(String.valueOf(moneySpent));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
