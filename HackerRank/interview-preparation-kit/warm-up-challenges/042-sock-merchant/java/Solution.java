import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the sockMerchant function below.
    static int sockMerchant(int n, int[] ar) {
        if (n < 1 || n > 100)
            throw new IllegalArgumentException();
        int[] socks = new int [n];
        for (int i = 0; i < n; i++) {
            if (ar[i] < 1 || ar[i] > 100)
                throw new IllegalArgumentException();
            socks[i] = ar[i];
        }

        int pairs = 0;
        for (int i = 0; i < n; i++) {
            if (socks[i] == 0) continue;
            for (int j = i + 1; j < n; j++) {
                if (socks[i] == socks[j]) {
                    socks[i] = socks[j] = 0;
                    pairs++;
                    break;
                }
            }
        }
        return pairs;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] ar = new int[n];

        String[] arItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arItem = Integer.parseInt(arItems[i]);
            ar[i] = arItem;
        }

        int result = sockMerchant(n, ar);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
