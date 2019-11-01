import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the matrixRotation function below.
    static void matrixRotation(List<List<Integer>> matrix, int r) {
        int m = matrix.size();
        int n = matrix.get(0).size();

        if (m < 2 || m > 300 || n < 2 || n > 300)
            throw new IllegalArgumentException();
        if (r < 1 || r > Math.pow(10, 9))
            throw new IllegalArgumentException();
        if (Math.min(m, n) % 2 != 0)
            throw new IllegalArgumentException();
        for (List<Integer> row: matrix) {
            for (Integer item: row) {
                if (item < 1 || item > Math.pow(10, 8))
                    throw new IllegalArgumentException();
            }
        }
        
        for (int layer = 0; m > 1 && n > 1; m -= 2, n -= 2, layer++) {
            int tmpR = r;
            int nOfItemsOnFirstLayer = 2*m + 2*n - 4;
            if (r > nOfItemsOnFirstLayer) {
                r = r % nOfItemsOnFirstLayer;
            }

            for (int p = 0; p < r; p++) {
                Integer tmp = matrix.get(layer).get(layer);
                // Left column of the matrix layer.
                for (int i = 0; i < m - 1; i++) {
                    Integer swap = matrix.get(i + 1 + layer).get(layer);
                    matrix.get(i + 1 + layer).set(layer, tmp);
                    tmp = swap;
                }

                // tmp = a41
                // Bottom row of the matrix layer.
                for (int j = 0; j < n - 1; j++) {
                    Integer swap = matrix.get(m - 1 + layer)
                        .get(j  + 1 + layer);
                    matrix.get(m - 1 + layer).set(j + 1 + layer, tmp);
                    tmp = swap;
                }
                
                // tmp = a45
                // Right column of the matrix layer.
                for (int i = m - 1; i > 0; --i) {
                    Integer swap = matrix.get(i - 1 + layer)
                        .get(n - 1 + layer);
                    matrix.get(i - 1 + layer).set(n - 1 + layer, tmp);
                    tmp = swap;
                }

                // tmp = a15
                // Top row of the matrix layer.
                for (int j = n - 1; j > 0; --j) {
                    Integer swap = matrix.get(layer).get(j - 1 + layer);
                    matrix.get(layer).set(j - 1 + layer, tmp);
                    tmp = swap;
                }
            }
            r = tmpR;
        }

        for (List<Integer> row: matrix) {
            for (Integer item: row)
                System.out.print(item + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        String[] mnr = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int m = Integer.parseInt(mnr[0]);

        int n = Integer.parseInt(mnr[1]);

        int r = Integer.parseInt(mnr[2]);

        List<List<Integer>> matrix = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            String[] matrixRowTempItems = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            List<Integer> matrixRowItems = new ArrayList<>();

            for (int j = 0; j < n; j++) {
                int matrixItem = Integer.parseInt(matrixRowTempItems[j]);
                matrixRowItems.add(matrixItem);
            }

            matrix.add(matrixRowItems);
        }

        matrixRotation(matrix, r);

        bufferedReader.close();
    }
}
