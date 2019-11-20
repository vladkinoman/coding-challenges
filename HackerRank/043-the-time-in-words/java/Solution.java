import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the timeInWords function below.
    static String timeInWords(int h, int m) {
        if (h < 1 || h > 12 || m < 0 || m >= 60)
            throw new IllegalArgumentException();
        String oclock = "o' clock";
        String minute = "minute";
        String minutes = "minutes";
        String to = "to";
        String past = "past";
        String half = "half";
        String quarter = "quarter";
        String[] sNumbers = {"one", "two", "three", "four",
            "five", "six", "seven", "eight", "nine", "ten",
            "eleven", "twelve", "thirteen", "fourteen", 
            "fifteen", "sixteen", "seventeen", "eighteen",                "nineteen", "twenty"
        };

        int tmpm = m;
        if        (m > 30) m = 60 - m; 
        
        String result = null;
        if        (m == 0) {
            result = sNumbers[h - 1] + " " + oclock;
        } else if (m == 1) {
            result = sNumbers[m - 1] + " " + minute + " ";
        } else if (m == 15) {
            result = quarter + " ";
        } else if (m == 30) {
            result = half + " ";
        } else if (m > 1 && m <= 20) {
            result = sNumbers[m - 1] + " " + minutes + " ";
        } else if (m == 45) {
            result = quarter + " ";
        } else {
            int rightd = m % 10;
            int leftd = (m / 10) * 10;
            result = sNumbers[leftd - 1] + " "
            + sNumbers[rightd - 1] 
            + " " + minutes + " "; 
        }

        m = tmpm;
        if        (m >= 1 && m <= 30) {
            result += past + " " + sNumbers[h - 1];
        } else if (m > 30) {
            result += to + " " + sNumbers[h];
        }
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int h = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String result = timeInWords(h, m);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
