class ResistorColorDuo {
    private String[] bandColors= {"black", "brown", "red", "orange",
         "yellow", "green", "blue", "violet", "grey", "white"};

    int value(String[] colors) {
        int n = colors.length;
        int nBands = bandColors.length;
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < 2 && i < n ; i++) {
            for (int j = 0; j < nBands; j++) {
                if (colors[i].equals(bandColors[j])) {
                    s.append(String.format("%d", j));
                }
            }
        }
        return Integer.parseInt(s.toString());
    }
}
