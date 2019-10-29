import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the squares function below.
    static int squares(int a, int b) {
        if (a < 1 || a > b || b > Math.pow(10, 9))
            throw new IllegalArgumentException();

        int numberOfSquareIntegers = 0;
        // Use double type to compare this variable with sqrt value.
        double dInteger = 0; 
        
        int i = 0;
        for (i = a; i <= b; i++) {
            double value = Math.sqrt(i);
            dInteger = value - value % 1; // We save the dInteger.
            // Get the first occurence of the square integer.
            if (value == dInteger) { 
                break;
            }
        }

        // If there was one square dInteger.
        if (i <= b) {
            double squareInteger = 0;
            while (squareInteger <= b) {
                numberOfSquareIntegers++;
                dInteger++; // Get the next number to be raised to 2.
                squareInteger = dInteger * dInteger;
            }
        }

        return numberOfSquareIntegers;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        if (q < 1 || q > 100)
            throw new IllegalArgumentException();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String[] ab = scanner.nextLine().split(" ");

            int a = Integer.parseInt(ab[0]);

            int b = Integer.parseInt(ab[1]);

            int result = squares(a, b);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
