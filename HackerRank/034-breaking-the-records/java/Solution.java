import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the breakingRecords function below.
    static int[] breakingRecords(int[] scores) {
        int n = scores.length;
        
        if (1 > n || n > 1000)
            throw new IllegalArgumentException();
        for (int i = 0; i < n; i++) {
            if (scores[i] < 0 || scores[i] > Math.pow(10, 8))
                throw new IllegalArgumentException();
        }

        int[] nOfTimesRecordsChange = new int[2];
        int highestScore = scores[0];
        int lowestScore = scores[0];
        for (int i = 1; i < n; i++) {
            if (highestScore < scores[i]) {
                highestScore = scores[i];
                nOfTimesRecordsChange[0]++;
            }
                
            if (lowestScore > scores[i]) {
                lowestScore = scores[i];
                nOfTimesRecordsChange[1]++;
            }
                
        }

        return nOfTimesRecordsChange;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] scores = new int[n];

        String[] scoresItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int scoresItem = Integer.parseInt(scoresItems[i]);
            scores[i] = scoresItem;
        }

        int[] result = breakingRecords(scores);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
