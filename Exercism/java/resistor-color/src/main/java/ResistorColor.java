class ResistorColor {
    int colorCode(String color) {
        String[] colors = colors();
        int n = colors.length;
        for (int i = 0; i < n; i++) {
            if (colors[i].equals(color))
                return i;
        }
        return -1;
    }

    String[] colors() {
        return new String[] {"black", "brown", "red", "orange",
         "yellow", "green", "blue", "violet", "grey", "white"};
    }
}
