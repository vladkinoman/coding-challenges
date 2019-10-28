import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the kangaroo function below.
    static String kangaroo(int x1, int v1, int x2, int v2) {
        if(x1 < 0 || x1 > 10000 || x2 < 0 || x2 > 10000 || x1 > x2)
            throw new IllegalArgumentException("0 <= x1 < x2 <= 10000");
        if(v1 < 1 || v1 > 10000)
            throw new IllegalArgumentException("1 <= v1 <= 10000");
        if(v2 < 1 || v2 > 10000)
            throw new IllegalArgumentException("1 <= v2 <= 10000");
        
        String yes = "YES";
        String no = "NO";
        if(v2 - v1 == 0) return no;
        int s2 = v2 * (x1 - x2) / (v2 - v1);
        int s1 = s2 + x2 - x1;

        if(s1 > 0 && s2 > 0 && (s1%v1) == (s2%v2))
            return yes;
        else
            return no;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("out.txt"/*System.getenv("OUTPUT_PATH")*/));

        String[] x1V1X2V2 = scanner.nextLine().split(" ");

        int x1 = Integer.parseInt(x1V1X2V2[0]);

        int v1 = Integer.parseInt(x1V1X2V2[1]);

        int x2 = Integer.parseInt(x1V1X2V2[2]);

        int v2 = Integer.parseInt(x1V1X2V2[3]);

        String result = kangaroo(x1, v1, x2, v2);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
