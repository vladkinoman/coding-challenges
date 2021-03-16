import java.util.HashMap;

public class PangramChecker {
    private HashMap<Character, Integer> alphaOccurences;

    public PangramChecker() {
        alphaOccurences = new HashMap<>();
        char c = 'a';
        for (int i = 0; i < 26; i++, c++) {
            alphaOccurences.put(c, 0);
        }
    }

    public boolean isPangram(String input) {
        if (input == null) {
            throw new IllegalArgumentException();
        }

        String s = new String(input);
        s = s.toLowerCase();
        System.out.println(s);        
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c >= 'a' && c <= 'z') {
                alphaOccurences.replace(c, 1);
            }
        }

        return !alphaOccurences.containsValue(0);
    }

}
