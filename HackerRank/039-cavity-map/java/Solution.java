import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the cavityMap function below.
    static String[] cavityMap(String[] grid) {
        int n = grid.length;
        if (n < 1 || n > 100)
            throw new IllegalArgumentException();
        
        if (n == 1) return grid;
        String[] result = new String[n];
        result[0] = grid[0];
        int i = 1;
        for (; i < n - 1; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; j++) {
                if (j == 0 || j == n - 1) {
                    sb.append(grid[i].charAt(j));
                    continue;
                }   
                boolean isCavity = (grid[i]
                .charAt(j-1) < grid[i].charAt(j)
                && grid[i-1].charAt(j) < grid[i].charAt(j)
                && grid[i].charAt(j+1) < grid[i].charAt(j)
                && grid[i+1].charAt(j) < grid[i].charAt(j));
                if (!isCavity) {
                    sb.append(grid[i].charAt(j));
                } else if (isCavity) {
                    sb.append('X');
                }
            }
            result[i] = sb.toString();
        }
        result[i] = grid[i];
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String[] grid = new String[n];

        for (int i = 0; i < n; i++) {
            String gridItem = scanner.nextLine();
            grid[i] = gridItem;
        }

        String[] result = cavityMap(grid);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(result[i]);

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
