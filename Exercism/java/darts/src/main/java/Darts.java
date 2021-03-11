import java.lang.Math;
class Darts {
    private final int score;

    Darts(double x, double y) {
        double l = Math.sqrt(x*x + y*y);
        if        (l <= 1) {
            score = 10;
        } else if (l <= 5) {
            score = 5;
        } else if (l <= 10) {
            score = 1;
        } else {
            score = 0;
        }
    }

    int score() {
        return score;
    }

}
