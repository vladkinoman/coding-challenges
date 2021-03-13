class RnaTranscription {

    String transcribe(String dnaStrand) {
        int n = dnaStrand.length();
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < n; i++) {
            char c;
            switch (c = dnaStrand.charAt(i)) {
                case 'G':
                    s.append('C');
                    break;
                case 'C':
                    s.append('G');
                    break;
                case 'T':
                    s.append('A');
                    break;
                case 'A':
                    s.append('U');
                    break;
                default:
                    s.append(c);
                    break;
            }
        }
        return s.toString();
    }
}
