import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    private static final int DAYTAB [][] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    private static final int PROGRAMMER_DAY = 256;

    // Complete the solve function below.
    static String solve(int year) {
        if(year < 1700 || year > 2700)
            throw new IllegalArgumentException("1700 <= year <= 2700");

        int day = 0;
        int month = 0;
        int l = 0; // leap
        if((year < 1918 && (year % 4 == 0))
            || (year > 1918 && (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)))
            l = 1;

        for (int i = 0, sum = 0; i < 12; ++i)
        {
            if((sum + DAYTAB[l][i]) > PROGRAMMER_DAY)
            {
                day = PROGRAMMER_DAY - sum;
                month = i + 1;
                break;
            }
            if(year == 1918 && i == 1) sum += DAYTAB[l][i] - 14;
            else sum += DAYTAB[l][i];
        }

        String sDate = null;
            if(day < 10 && month < 10)
                sDate = "0"+ day + ".0" + month + "." + year;
            else if(day < 10 && month >= 10)
                sDate = "0"+ day + "."  + month + "." + year;
            else if(day >= 10 && month < 10)
                sDate =      day + ".0" + month + "." + year;
            else if(day >= 10 && month >= 10)
                sDate =      day + "."  + month + "." + year;
        return sDate;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("out.txt"/*System.getenv("OUTPUT_PATH")*/));

        int year = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String result = solve(year);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
