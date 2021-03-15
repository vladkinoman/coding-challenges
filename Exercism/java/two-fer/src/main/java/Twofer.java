public class Twofer {
    public String twofer(String name) {
        String s = null;
        try {
            s = new String(name);
        }
        catch (NullPointerException e) {
            s = "you";
        }
        return String.format("One for %s, one for me.", s);
    }
}
