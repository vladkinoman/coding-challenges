import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class BruteForceSolution {
    private static boolean isObstacleFound(int i, int j, int k,
            int[][] obstacles) {
        boolean isObstacleFound = false;
        for (int p = 0; p < k; p++) {
            if (i == obstacles[p][0] && j == obstacles[p][1]) {
                isObstacleFound = true;
                break;
            }
        }
        return isObstacleFound;
    }

    // Complete the queensAttack function below.
    static int queensAttack(int n, int k, int r_q, int c_q, int[][] obstacles) {
        if (n <= 0 || n > Math.pow(10, 5) 
            || k < 0 || k > Math.pow(10, 5))
            throw new IllegalArgumentException();
        for (int i = 0; i < obstacles.length; i++) {
            if (r_q == obstacles[i][0] && c_q == obstacles[i][1])
                throw new IllegalArgumentException();
        }

        int nOfSquaresQueenCanAttack = 0;
        // Top left corner.
        /*
            a x x
            x Q x
            x x x
        */
        int i = r_q + 1;
        int j = c_q - 1;
        // Indexing starts at 1.
        for (; j >= 1 && i <= n; i++, --j) {
            if (!isObstacleFound(i, j, k, obstacles))
                nOfSquaresQueenCanAttack++;
            else break;
        }
        
        
        // Left middle corner.
        /*
            x x x
            a Q x
            x x x
        */
        i = r_q;
        j = c_q - 1;
        for (; j >= 1; --j) {
            if (!isObstacleFound(i, j, k, obstacles))
                nOfSquaresQueenCanAttack++;
            else break;
        }

        
        // Bottom left corner.
        /*
            x x x
            x Q x
            a x x
        */
        i = r_q - 1;
        j = c_q - 1;
        for (; j >= 1 && i >= 1; --i, --j) {
            if (!isObstacleFound(i, j, k, obstacles))
                nOfSquaresQueenCanAttack++;
            else break;
        }

        
        // Bottom middle corner.
        /*
            x x x
            x Q x
            x a x
        */
        i = r_q - 1;
        j = c_q;
        for (; i >= 1; --i) {
            if (!isObstacleFound(i, j, k, obstacles))
                nOfSquaresQueenCanAttack++;
            else break;
        }

        // Bottom right corner.
        /*
            x x x
            x Q x
            x x a
        */
        i = r_q - 1;
        j = c_q + 1;
        for (; i >= 1 && j <= n; --i, j++) {
            if (!isObstacleFound(i, j, k, obstacles))
                nOfSquaresQueenCanAttack++;
            else break;
        }

        // Right middle corner.
        /*
            x x x
            x Q a
            x x x
        */
        i = r_q;
        j = c_q + 1;
        for (; j <= n; j++) {
            if (!isObstacleFound(i, j, k, obstacles))
                nOfSquaresQueenCanAttack++;
            else break;
        }

        // Top right corner.
        /*
            x x a
            x Q x
            x x x
        */
        i = r_q + 1;
        j = c_q + 1;
        for (; i <= n && j <= n; i++, j++) {
            if (!isObstacleFound(i, j, k, obstacles))
                nOfSquaresQueenCanAttack++;
            else break;
        }

        // Top middle corner.
        /*
            x a x
            x Q x
            x x x
        */
        i = r_q + 1;
        j = c_q;
        for (; i <= n; i++) {
            if (!isObstacleFound(i, j, k, obstacles))
                nOfSquaresQueenCanAttack++;
            else break;
        }

        return nOfSquaresQueenCanAttack;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        String[] r_qC_q = scanner.nextLine().split(" ");

        int r_q = Integer.parseInt(r_qC_q[0]);

        int c_q = Integer.parseInt(r_qC_q[1]);

        int[][] obstacles = new int[k][2];

        for (int i = 0; i < k; i++) {
            String[] obstaclesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int obstaclesItem = Integer.parseInt(obstaclesRowItems[j]);
                obstacles[i][j] = obstaclesItem;
            }
        }

        int result = queensAttack(n, k, r_q, c_q, obstacles);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
