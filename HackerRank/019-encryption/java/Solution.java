import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the encryption function below.
    static String encryption(String s) {
        if (s.length() < 1 || s.length() > 81)
            throw new IllegalArgumentException();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != ' ')
                sb.append(c);
        }
        s = sb.toString();
        int L = s.length();
        int m = (int) Math.floor(Math.sqrt(L));
        int n = (int) Math.ceil(Math.sqrt(L));
        while (m * n < L) {
            m++;
        }
        StringBuilder sbReturn = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (n * j + i < L)
                    sbReturn.append(s.charAt(n * j + i));
            }
            sbReturn.append(' ');
        }
        return sbReturn.toString();
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = encryption(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
