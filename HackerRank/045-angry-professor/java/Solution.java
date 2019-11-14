import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the angryProfessor function below.
    static String angryProfessor(int k, int[] a) {
        int n = a.length;
        if (k < 1 || k > n 
        || n < 1 || n > 1000)
            throw new IllegalArgumentException();
        for (int i = 0; i < n; i++) {
            if (a[i] < -100 
            || a[i] > 100)
                throw new IllegalArgumentException();
        }

        String sYes = "YES";
        String sNo = "NO";
        int arrivedOnTime = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= 0) arrivedOnTime++;
        }
        if (arrivedOnTime >= k) return sNo;
        return sYes;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        if (t < 1 || t > 10)
            throw new IllegalArgumentException();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] nk = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nk[0]);

            int k = Integer.parseInt(nk[1]);

            int[] a = new int[n];

            String[] aItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int aItem = Integer.parseInt(aItems[i]);
                a[i] = aItem;
            }

            String result = angryProfessor(k, a);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
