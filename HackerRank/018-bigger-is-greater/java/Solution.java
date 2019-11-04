import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    // Complete the biggerIsGreater function below.
    static String biggerIsGreater(String w) {
        int n = w.length();
        if (n < 1 || n > 100)
            throw new IllegalArgumentException();
        
        String sNoAnswer = "no answer";
        char[] caWord = w.toCharArray();
        for (int i = n - 2; i >= 0; --i) {
            if (caWord[i] < caWord[i + 1]) {
                int smallestThatIsBigger = -1;
                for (int j = i + 1; j < n; j++) {
                    if (caWord[i] < caWord[j] && smallestThatIsBigger < 0
                    || smallestThatIsBigger > 0 && caWord[i] < caWord[j] 
                        && caWord[j] < caWord[smallestThatIsBigger]) {
                        smallestThatIsBigger = j;
                    }
                }
                if (smallestThatIsBigger > 0) {
                    // Swap ith with the smallest one that is bigger than ith.
                    char tmp = caWord[i];
                    caWord[i] = caWord[smallestThatIsBigger];
                    caWord[smallestThatIsBigger] = tmp;
                    // Sort the right side of the array.
                    Arrays.sort(caWord, i + 1, n);
                    StringBuilder sb = new StringBuilder();
                    for (int c = 0; c < n; c++) {
                        sb.append((char)caWord[c]);
                    }
                    return sb.toString();
                }
            }
        }
        return sNoAnswer;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int T = scanner.nextInt();
        if (T < 1 || T > Math.pow(10, 5))
            throw new IllegalArgumentException();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int TItr = 0; TItr < T; TItr++) {
            String w = scanner.nextLine();

            String result = biggerIsGreater(w);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
