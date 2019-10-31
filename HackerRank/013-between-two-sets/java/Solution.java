import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'getTotalX' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY a
     *  2. INTEGER_ARRAY b
     */

    public static int getTotalX(List<Integer> a, List<Integer> b) {
        int n = a.size();
        int m = b.size();

        if (n < 1 || n > 10 || m < 1 || m > 10)
            throw new IllegalArgumentException();
        for(int i: a) {
            if (i < 1 || i > 100)
                throw new IllegalArgumentException();
        }
        for (int i: b) {
            if (i < 1 || i > 100)
                throw new IllegalArgumentException();
        }

        
        int p = Collections.max(a);
        int q = Collections.min(b);
        if (p > q) {
            int swap = p;
            p = q;
            q = swap;
        }
        int nOfIntsBetweenAB = 0;
        for (int i = p; i <= q; i++) {
            boolean isNumberBetweenTwoSets = true;
            
            for (int ia: a) {
                isNumberBetweenTwoSets = isNumberBetweenTwoSets 
                && (i % ia == 0);
                if (!isNumberBetweenTwoSets)
                    break;
            }
            
            if (!isNumberBetweenTwoSets)
                    continue;

            for (int ib: b) {
                isNumberBetweenTwoSets  = isNumberBetweenTwoSets 
                && (ib % i  == 0);
                if (!isNumberBetweenTwoSets)
                    break;
            }

            if (isNumberBetweenTwoSets)
                nOfIntsBetweenAB++;
        }

        return nOfIntsBetweenAB;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int m = Integer.parseInt(firstMultipleInput[1]);

        String[] arrTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        List<Integer> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrTemp[i]);
            arr.add(arrItem);
        }

        String[] brrTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        List<Integer> brr = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            int brrItem = Integer.parseInt(brrTemp[i]);
            brr.add(brrItem);
        }

        int total = Result.getTotalX(arr, brr);

        bufferedWriter.write(String.valueOf(total));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
