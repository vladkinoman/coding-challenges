import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the chocolateFeast function below.
    /*
    n: an integer representing Bobby's initial amount of money
    c: an integer representing the cost of a chocolate bar
    m: an integer representing the number of wrappers he can turn in for a free bar
    */
    static int chocolateFeast(int n, int c, int m) {
        if (n < 2 || n > Math.pow(10, 5) || c < 1 
        || c > n || m < 2
        || m > n)
            throw new IllegalArgumentException();

        int chocos = n / c;
        int wrappers = chocos;
        while (wrappers >= m) {
            chocos += wrappers / m;
            wrappers += wrappers / m + wrappers % m - wrappers;
        }
        return chocos;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        if (t < 1 || t > 1000)
            throw new IllegalArgumentException();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] ncm = scanner.nextLine().split(" ");

            int n = Integer.parseInt(ncm[0]);

            int c = Integer.parseInt(ncm[1]);

            int m = Integer.parseInt(ncm[2]);

            int result = chocolateFeast(n, c, m);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
