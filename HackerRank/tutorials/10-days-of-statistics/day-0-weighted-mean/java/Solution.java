import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        if (N < 5 || N > 50)
            throw new IllegalArgumentException();
        int[] x = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = scanner.nextInt();
            if (x[i] <= 0 || x[i] > 100)
                throw new IllegalArgumentException();
        }
        int[] w = new int[N];
        for (int i = 0; i < N; i++) {
            w[i] = scanner.nextInt();
            if (w[i] <= 0 || w[i] > 100)
                throw new IllegalArgumentException();
        }
        scanner.close();

        long numerator = 0;
        long denominator = 0;
        for (int i = 0; i < N; i++) {
            numerator += (long) x[i] * w[i];
            denominator += (long) w[i];
        }

        System.out.println(Math.round(
            (double)numerator/denominator * 10) / 10.0);
    }
}

