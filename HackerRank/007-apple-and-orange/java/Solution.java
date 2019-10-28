import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.lang.System;

public class Solution {

    // Complete the countApplesAndOranges function below.
    static void countApplesAndOranges(int s, int t, int a, 
        int b, int[] apples, int[] oranges) {
        /***************** CONSTRAINTS *******************/
        if(s < 1 || t < 1 || a < 1 || b < 1 
            || apples.length < 1 || oranges.length < 1
            || s > 100000 || t > 100000 || a > 100000 || b > 100000 
            || apples.length > 100000 || oranges.length > 100000)
            throw new IllegalArgumentException("1<=s,t,a,b,m,n<=10^5");
        if(a > s || a > t || a > b || s > t || s > b || t > b)
            throw new IllegalArgumentException("a < s < t < b");
        for (int apple : apples)
            if(apple < -100000 || apple > 100000)
                throw new IllegalArgumentException("-10^5 <= d <= 10^5");
        for (int orange : oranges)
            if(orange < -100000 || orange > 100000)
                throw new IllegalArgumentException("-10^5 <= d <= 10^5");
        /**************************************************/
        int countApples = 0;
        for (int apple : apples)
        {
            int position = apple + a;   
            if(position >= s && position <= t)
                countApples++;
        }    
            
        int countOranges = 0; 
        for (int orange : oranges)
        {
            int position = orange + b; 
            if(position >= s && position <= t)
                countOranges++;
        }

        System.out.println(countApples);
        System.out.println(countOranges);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String[] st = scanner.nextLine().split(" ");

        int s = Integer.parseInt(st[0]);

        int t = Integer.parseInt(st[1]);

        String[] ab = scanner.nextLine().split(" ");

        int a = Integer.parseInt(ab[0]);

        int b = Integer.parseInt(ab[1]);

        String[] mn = scanner.nextLine().split(" ");

        int m = Integer.parseInt(mn[0]);

        int n = Integer.parseInt(mn[1]);

        int[] apples = new int[m];

        String[] applesItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            int applesItem = Integer.parseInt(applesItems[i]);
            apples[i] = applesItem;
        }

        int[] oranges = new int[n];

        String[] orangesItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int orangesItem = Integer.parseInt(orangesItems[i]);
            oranges[i] = orangesItem;
        }

        countApplesAndOranges(s, t, a, b, apples, oranges);

        scanner.close();
    }
}
