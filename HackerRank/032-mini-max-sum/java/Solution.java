import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    private static final int UPPER_BOUND = 1000000000;
    private static final int LOWER_BOUND = 1;
    
    private static int findNextMin(int arr[])
    {
        int min = UPPER_BOUND + 1;
        int indexMin = 0;
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[i] != 0 && arr[i] < min)
            {
                min = arr[i];
                indexMin = i;
            }
        }
        arr[indexMin] = 0;
        return min;
    }

    private static int findNextMax(int arr[])
    {
        int max = LOWER_BOUND - 1;
        int indexMax = 0;
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[i] != 0 && arr[i] > max)
            {
                max = arr[i];
                indexMax = i;
            }
        }
        arr[indexMax] = 0;
        return max;
    }
    
    // Complete the miniMaxSum function below.
    static void miniMaxSum(int[] arr) {
        int amin[] = new int [arr.length];
        int amax[] = new int [arr.length];
         for(int i = 0; i < arr.length; i++)
         {
             amin[i] = amax[i] = arr[i];
             if(arr[i] < LOWER_BOUND || arr[i] > UPPER_BOUND)
                throw new IllegalArgumentException();
         }
            
        long minSum = 0L;
        long maxSum = 0L;
        for(int i = 0; i < arr.length - 1; i++)
        {
            minSum += findNextMin(amin);
            maxSum += findNextMax(amax);
        }
        System.out.println(minSum + " " + maxSum);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[] arr = new int[5];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < 5; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        miniMaxSum(arr);

        scanner.close();
    }
}
