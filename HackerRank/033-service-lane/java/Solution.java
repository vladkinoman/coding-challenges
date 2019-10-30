import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    // Check the constraints.
    private static void validate(int n, int t, int[] width, int[][] cases) {
        if (n < 2 || n > 100000)
            throw new IllegalArgumentException();
        
        if (t < 1 || t > 1000)
            throw new IllegalArgumentException();

        for (int i = 0; i < cases.length; i++)
            if (cases[i][0] < 0 || cases[i][0] >= cases[i][1]
            ||cases[i][1] >= n || (cases[i][1] - cases[i][0] + 1) < 2
            || (cases[i][1] - cases[i][0] + 1) > Math.min(n, 1000))
                throw new IllegalArgumentException();
        
        for (int k = 0; k < n; k++)
            if (width[k] < 1 || width[k] > 3)
                throw new IllegalArgumentException();
    }
    // Complete the serviceLane function below.
    static int[] serviceLane(int n, int t, int[] width, int[][] cases) {
        validate(n, t, width, cases);
        
        int[] largestVehicles = new int [cases.length];

        for (int i = 0; i < cases.length; i++) {
            // The max width you can get is 3.
            int min = 4; 
            int entry = cases[i][0];
            int exit  = cases[i][1];
            for (int j = entry; j <= exit; j++) {
                if (width[j] < min) min = width[j];
            }
            largestVehicles[i] = min;
        }

        return largestVehicles;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nt = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nt[0]);

        int t = Integer.parseInt(nt[1]);

        int[] width = new int[n];

        String[] widthItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int widthItem = Integer.parseInt(widthItems[i]);
            width[i] = widthItem;
        }

        int[][] cases = new int[t][2];

        for (int i = 0; i < t; i++) {
            String[] casesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int casesItem = Integer.parseInt(casesRowItems[j]);
                cases[i][j] = casesItem;
            }
        }

        int[] result = serviceLane(n, t, width, cases);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
