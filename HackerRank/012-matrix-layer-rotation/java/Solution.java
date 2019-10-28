import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the matrixRotation function below.
    static void matrixRotation(int[][] matrix) {


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String[] mnr = scanner.nextLine().split(" ");

        int m = Integer.parseInt(mnr[0]);

        int n = Integer.parseInt(mnr[1]);

        int r = Integer.parseInt(mnr[2]);

        int[][] matrix = new int[m][n];

        for (int i = 0; i < m; i++) {
            String[] matrixRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < n; j++) {
                int matrixItem = Integer.parseInt(matrixRowItems[j]);
                matrix[i][j] = matrixItem;
            }
        }

        matrixRotation(matrix);

        scanner.close();
    }
}
