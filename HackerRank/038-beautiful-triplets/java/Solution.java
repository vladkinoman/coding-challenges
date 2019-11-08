import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the beautifulTriplets function below.
    static int beautifulTriplets(int d, int[] arr) {
        int n = arr.length;
        if (n < 1 || n > Math.pow(10, 4))
            throw new IllegalArgumentException();
        if (d < 1 || d > 20)
            throw new IllegalArgumentException();
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] < 0 || arr[i - 1] > 2 * Math.pow(10, 4))
                throw new IllegalArgumentException();
            if (arr[i - 1] > arr[i])
                throw new IllegalArgumentException();
        }
        if (arr[n - 1] < 0 || arr[n - 1] > 2 * Math.pow(10, 4))
                throw new IllegalArgumentException();
        
        int nOfBeautifulTriples = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (arr[j] - arr[i] == d && Arrays.binarySearch(
                    arr, j + 1, n, d + arr[j]) > 0)
                    nOfBeautifulTriples++;
            }
        }
        return nOfBeautifulTriples;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nd = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nd[0]);

        int d = Integer.parseInt(nd[1]);

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int result = beautifulTriplets(d, arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
