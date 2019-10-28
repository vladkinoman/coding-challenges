import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the birthdayCakeCandles function below.
    static int birthdayCakeCandles(int[] ar) {
    	if(ar.length < 1 || ar.length > 100000)
			throw new NegativeArraySizeException(
					"Count of candles must be greater 1 <= n <=10^5");
		
		for (int i = 0; i < ar.length; ++i)
			if(ar[i] < 1 || ar[i] > 10000000)
				throw new IllegalArgumentException(
					"Height of candles must be greater 1 <= height <=10^7");
    	
    	int max = ar[0];
    	int countCandles = 0;
    	for (int i = 0; i < ar.length ; i++)
    	{
    		if(max < ar[i])
    		{
    			max = ar[i];
    			countCandles = 0;	
    		} 
    		if(max == ar[i]) countCandles++;
    	}	

    	return countCandles;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("out.txt"/*System.getenv("OUTPUT_PATH")*/));

        int arCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] ar = new int[arCount];

        String[] arItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < arCount; i++) {
            int arItem = Integer.parseInt(arItems[i]);
            ar[i] = arItem;
        }

        int result = birthdayCakeCandles(ar);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
