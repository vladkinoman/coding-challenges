import java.util.*;
class Solution {
    
    private final static String[] phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs",
                          "tuv", "wxyz"};
    
    private int[] recurrentIndexBacktracking(int[] indexArray, int[] iDigits, int i) {
        if (i == -1) return indexArray;
        
        if (indexArray[i] == phone[iDigits[i]].length() - 1) {
            indexArray[i] = 0;
            i--;
            return recurrentIndexBacktracking(indexArray, iDigits, i);
        }
        
        indexArray[i]++;
        
        return recurrentIndexBacktracking(indexArray, iDigits, -1);
    }
    
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) return new Vector<String>();
        for (int i = 0; i < digits.length(); i++) {
            int c = Integer.parseInt(String.valueOf(digits.charAt(i)));
            if (c < 2 || c > 9)
                throw new IllegalArgumentException();
        }
        
        
        int[] iDigits = new int [digits.length()];
        int numberOfCombinations = 1;
        for (int i = 0; i < digits.length(); i++) {
            int c = Integer.parseInt(String.valueOf(digits.charAt(i)));
            iDigits[i] = c - 2; // easy access
            numberOfCombinations *= phone[iDigits[i]].length();
        }
        
        List<String> lOfLetterCombinations = new Vector<>();
        int[] indexArray = new int [digits.length()];
        for (int i = 0; i < numberOfCombinations; i++) {
            String s = "";
            
            for (int j = 0; j < digits.length(); j++) {
                s = new String (s + String.valueOf(phone[iDigits[j]]
                    .charAt(indexArray[j])));    
                
                recurrentIndexBacktracking(indexArray, iDigits, j);
            }
            
            // creating the string containing the letter combination            
            lOfLetterCombinations.add(s);       
        }
        
        return lOfLetterCombinations;
    }
}