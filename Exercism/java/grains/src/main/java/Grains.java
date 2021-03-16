import java.math.BigInteger;

class Grains {

    BigInteger grainsOnSquare(final int square) {
        if (square < 1 || square > 64) {
            throw new IllegalArgumentException(
                "square must be between 1 and 64");
        }
        return (new BigInteger("2")).pow(square-1);
    }

    BigInteger grainsOnBoard() {
        return (new BigInteger("2")).pow(64)
        .subtract(new BigInteger("1"));
    }

}
