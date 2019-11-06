import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class QueueSlowSolution {

    // Complete the saveThePrisoner function below.
    static int saveThePrisoner(int n, int m, int s) {
        if (n < 1 || n > Math.pow(10, 9) || m < 1 || m > Math.pow(10, 9)
        || s < 1 || s > n)
            throw new IllegalArgumentException();
        
        Queue<Integer> q1 = new LinkedList<>();
        // Adding chairs.
        for (int i = 1, j = s; i <= n; i++, j++) {
            if (j > n) j = 1;
            q1.add(j);
        }

        int chair = 0;
        Queue<Integer> q2 = new LinkedList<>();
        boolean isQ1active = true;
        for (int i = m; i > 0; --i) {
            // Continue removing from Q[i] until we get all elements.
            if (isQ1active) {
                chair = q1.remove();
                q2.add(chair);
                if (q1.isEmpty())
                    isQ1active = false;
            } else {
                chair = q2.remove();
                q1.add(chair);
                if (q2.isEmpty())
                    isQ1active = true;
            }
        }

        return chair;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        if (t < 1 || t > 100)
            throw new IllegalArgumentException();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] nms = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nms[0]);

            int m = Integer.parseInt(nms[1]);

            int s = Integer.parseInt(nms[2]);

            int result = saveThePrisoner(n, m, s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
