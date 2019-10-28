import java.util.*;
class Solution {
    
    private final static String[] phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs",
                          "tuv", "wxyz"};
    
    private String returnCombination(int digit) {
        for (int i = 0; i < phone[digit].length(); i++) {
            
        }
    }
    
    public List<String> letterCombinations(String digits) {
        
        for (int i = 0; i < digits.length(); i++) {
            int c = Integer.parseInt(String.valueOf(digits.charAt(i)));
            if (c < 2 || c > 9)
                throw new IllegalArgumentException();
        }
        
        
        Integer[] iDigits = new Integer [digits.length()];
        int numberOfCombinations = 1;
        for (int i = 0; i < digits.length(); i++) {
            int c = Integer.parseInt(String.valueOf(digits.charAt(i)));
            numberOfCombinations *= c;
            iDigits[i] = c - 2; // easy access later
        }
        
        List<String> lOfLetterCombinations = new Vector<>();
        for (int i = 0; i < numberOfCombinations; i++) {
            
        }
        
        
        for (int i = 0; i < phone[iDigits[0]].length(); i++) {
            String s = new String(String.valueOf(phone[iDigits[0]].charAt(i)) 
                                      + String.valueOf(phone[iDigits[1]].charAt(j)));
                lOfLetterCombinations.add(s);
        }
        
        return lOfLetterCombinations;
    }
}