class ReverseString {

    String reverse(String inputString) {
        String sReversedString = "";
        for (int i = 0; i < inputString.length(); i++) {
            sReversedString = inputString.charAt(i) + sReversedString;
        }
        return sReversedString;
    }

}
