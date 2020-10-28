import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;



public class Solution {

    // Complete the luckBalance function below.
    static int luckBalance(int k, int[][] contests) {
        int[][] aa = contests.clone();
        int n = aa.length;

        java.util.Arrays.sort(aa, new java.util.Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                int cmp_importance = Integer.compare(a[1], b[1]);
                if (cmp_importance < 0 || cmp_importance > 0) {
                    return cmp_importance;
                } else return -Integer.compare(a[0], b[0]);
            }
        });

        int max_luck_balance = 0;

        for (int i = 0; i < n; i++) {
            if (aa[i][1] == 0) {
                max_luck_balance += aa[i][0];
            } else if (k > 0) {
                max_luck_balance += aa[i][0];
                --k;
            } else {
                max_luck_balance -= aa[i][0];
            }
        }

        return max_luck_balance;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        int[][] contests = new int[n][2];

        for (int i = 0; i < n; i++) {
            String[] contestsRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int contestsItem = Integer.parseInt(contestsRowItems[j]);
                contests[i][j] = contestsItem;
            }
        }

        int result = luckBalance(k, contests);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

