import java.util.*;
class Solution {
    public List<String> letterCombinations(String digits) {
        Integer[] iDigits = new Integer [digits.length()];
        for (int i = 0; i < digits.length(); i++) {
            int c = Integer.parseInt(String.valueOf(digits.charAt(i)));
            if (c < 2 || c > 9)
                throw new IllegalArgumentException();
            iDigits[i] = c - 2; // easy access later
        }
        
        String[] phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs",
                          "tuv", "wxyz"};
        
        List<String> lOfLetterCombinations = new Vector<>(); ;
        // let's try to complete this assignment with two letters
        // generalize it later.
        for (int i = 0; i < phone[iDigits[0]].length(); i++) {
            for (int j = 0; j < phone[iDigits[1]].length(); j++) {
                String s = new String(String.valueOf(phone[iDigits[0]].charAt(i)) 
                                      + String.valueOf(phone[iDigits[1]].charAt(j)));
                lOfLetterCombinations.add(s);
            }
        }
        
        return lOfLetterCombinations;
    }
}