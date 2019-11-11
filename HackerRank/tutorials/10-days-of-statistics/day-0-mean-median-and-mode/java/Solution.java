 import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        if (N < 10 || N > 2500)
            throw new IllegalArgumentException();
        int[] x = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = scanner.nextInt();
            if (x[i] <= 0 || x[i] > Math.pow(10, 5))
                throw new IllegalArgumentException();
        }
        scanner.close();
        
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += x[i];
        }
        /*
        Print the mean on a new line, to a scale of 1 decimal place.
        */
        double mean = Math.round((double) sum / N * 10) / 10.0;
        System.out.println(mean);

        
        Arrays.sort(x);
        /*
        Print the mean on a new line, to a scale of 1 decimal place.
        */
        double median = Math.round((double) (x[(N-1)/2] + x[(N-1)/2+1]) 
            / 2 * 10) / 10.0;
        System.out.println(median);
        
        int mode = 0;
        int numberOfMode = 0;
        for (int i = 0, j = 0; i < N; i = j) {
            int numberOfCurr = 1;
            for (j = i + 1; j < N && x[i] == x[j]; j++) {
                numberOfCurr++;
            }
            if (numberOfMode < numberOfCurr 
            || numberOfMode == numberOfCurr && x[i] < mode) {
                mode = x[i];
                numberOfMode = numberOfCurr;
            }        
        }
        /*
        Print the mode on a new line; 
        if more than one such value exists, print the numerically smallest one.
        */
        System.out.println(mode);
    }
}

