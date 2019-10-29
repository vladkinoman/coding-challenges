import java.util.*;
class Solution {
    
    private final static String[] PHONE = {"abc", "def", "ghi", "jkl", "mno", "pqrs",
                          "tuv", "wxyz"};
    
    private int[] recurrentIndexBacktracking(int i, int[] arrayOfIndices, int[] arrayOfDigits,
                    boolean isFrontChanged) {
        
        if (i == -1) return arrayOfIndices;
        
        if (arrayOfIndices[i] == PHONE[arrayOfDigits[i]].length() - 1) {
            arrayOfIndices[i] = 0;
            return recurrentIndexBacktracking(i - 1, arrayOfIndices, arrayOfDigits, true);
        }
        
        if (isFrontChanged || i == arrayOfIndices.length - 1) arrayOfIndices[i]++;
        
        return recurrentIndexBacktracking(-1, arrayOfIndices, arrayOfDigits, false);
    }
    
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) return new Vector<String>();
        int numberOfDigits = digits.length();
        
        // Validate.
        for (int i = 0; i < numberOfDigits; i++) {
            int c = Integer.parseInt(String.valueOf(digits.charAt(i)));
            if (c < 2 || c > 9)
                throw new IllegalArgumentException();
        }
        
        int[] arrayOfDigits = new int [numberOfDigits];
        int numberOfCombinations = 1;
        for (int i = 0; i < numberOfDigits; i++) {
            int c = Integer.parseInt(String.valueOf(digits.charAt(i)));
            arrayOfDigits[i] = c - 2; // easy access
            numberOfCombinations *= PHONE[arrayOfDigits[i]].length();
        }
        
        List<String> combinationsOfLetters = new Vector<>();
        int[] arrayOfIndices = new int [numberOfDigits];
        for (int i = 0; i < numberOfCombinations; i++) {
            String s = "";
            
            for (int j = 0; j < numberOfDigits; j++) {
                s = new String (s + String.valueOf(PHONE[arrayOfDigits[j]]
                    .charAt(arrayOfIndices[j])));    
                
                if (j == numberOfDigits - 1)
                    recurrentIndexBacktracking(j, arrayOfIndices, arrayOfDigits, false);
            }
            
            // creating the string containing the combination of letters          
            combinationsOfLetters.add(s);       
        }
        
        return combinationsOfLetters;
    }
}